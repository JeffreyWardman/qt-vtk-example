#include "render.h"

#include <vtkActor.h>
#include <vtkArrowSource.h>
#include <vtkAxesActor.h>
#include <vtkCamera.h>
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkNamedColors.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkPlaneSource.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>
#include <vtkSphereSource.h>
#include <vtkTransform.h>
#include <vtkTransformPolyDataFilter.h>

namespace qtvtk::render {

Renderer::Renderer() { setup(false); };
Renderer::Renderer(bool addAxes) { setup(addAxes); };

Renderer::~Renderer() { close(); };

void Renderer::setup(bool addAxes) {
  renderer = vtkSmartPointer<vtkRenderer>::New();
  renderWindow = vtkSmartPointer<vtkRenderWindow>::New();

  renderWindow->SetWindowName("QTVTK Viewer");
  renderWindow->AddRenderer(renderer);
  renderWindow->SetSize(960, 960); // Set the size of the render window
  renderer->SetBackground(1.0f, 1.0f, 1.0f); // Set background color

  if (addAxes) {
    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
  }
}

void Renderer::removeActors() { this->renderer->RemoveAllViewProps(); }

void Renderer::show() {
  renderWindow->Render();
  if (renderWindowInteractor) {
    renderWindowInteractor->Start();
  }
}

void Renderer::close() {
  renderer->RemoveAllViewProps();
  renderWindow->Finalize();
  if (renderWindowInteractor) {
    renderWindowInteractor->TerminateApp();
  }
}
} // namespace qtvtk::render

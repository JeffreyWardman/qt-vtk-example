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
  // renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();

  renderWindow->SetWindowName("QTVTK Viewer");
  renderWindow->AddRenderer(renderer);
  renderWindow->SetSize(960, 960); // Set the size of the render window
  renderer->SetBackground(1.0f, 1.0f, 1.0f); // Set background color

  if (addAxes) {
    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    renderWindowInteractor->SetRenderWindow(renderWindow);
    // Prepare renderer scene
    // prepareScene();
  }
  // if (addAxes)
  // {
  //     this->widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
  //     renderWindowInteractor->SetRenderWindow(renderWindow);
  //     // Prepare renderer scene
  //     prepareScene();
  // }
  // else
  // {
  // }
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
  // // Clean up vtkOrientationMarkerWidget
  // if (widget)
  // {
  //     widget->SetEnabled(false);
  //     // widget->SetInteractor(nullptr);
  //     // widget->Delete();
  //     // widget = nullptr;
  // }

  // // Clean up vtkRenderWindowInteractor
  // if (renderWindowInteractor)
  // {
  //     renderWindowInteractor->SetRenderWindow(nullptr);  // Ensure interactor
  //     is detached from render window renderWindowInteractor->TerminateApp();
  //     // renderWindowInteractor->Delete();
  //     renderWindowInteractor = nullptr;
  // }

  // // Clean up vtkRenderWindow
  // if (renderWindow)
  // {
  //     renderWindow->Finalize();
  //     renderWindow->SetInteractor(nullptr);  // Ensure render window is
  //     detached from interactor
  //     // renderWindow->Delete();
  //     renderWindow = nullptr;
  // }

  // // Clean up vtkRenderer
  // if (renderer)
  // {
  //     renderer->RemoveAllViewProps();
  //     // renderer->Delete();
  //     renderer = nullptr;
  // }
  // // renderer->RemoveAllViewProps();
  // // renderWindow->Finalize();
  // // renderWindow = nullptr;

  // // if (renderWindowInteractor)
  // // {
  // //     // renderWindowInteractor->TerminateApp();
  // //     // renderWindowInteractor->SetRenderWindow(nullptr);  // Ensure
  // interactor is detached from render window
  // //     renderWindowInteractor->TerminateApp();
  // //     // renderWindowInteractor->Delete();
  // //     renderWindowInteractor = nullptr;
  // // }
}
} // namespace qtvtk::render

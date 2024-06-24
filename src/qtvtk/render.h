
#pragma once

#include <vtkOrientationMarkerWidget.h>
#include <vtkPolyData.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkSmartPointer.h>

#include <array>

namespace qtvtk::render {
class Renderer {
public:
  Renderer();
  explicit Renderer(bool addAxes);
  ~Renderer();

  void setup(bool addAxes = false);
  void removeActors();
  void show();
  void close();

  vtkSmartPointer<vtkRenderer> renderer;
  vtkSmartPointer<vtkRenderWindow> renderWindow;
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
  vtkSmartPointer<vtkOrientationMarkerWidget> widget;
};
} // namespace qtvtk::render
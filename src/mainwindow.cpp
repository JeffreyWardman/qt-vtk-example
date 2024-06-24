#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <qtvtk/render.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  connect(ui->pushButton, &QPushButton::clicked, this,
          &MainWindow::on_pushButton_clicked);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_clicked() {

  qtvtk::render::Renderer renderer;
  renderer.show();
  renderer.close();
  QMessageBox::information(this, "Message", "Hello, Qt!");
}

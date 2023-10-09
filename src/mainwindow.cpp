#include "mainwindow.h"
#include "fmt/core.h"
#include <qevent.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::resizeEvent(QResizeEvent *event){
  fmt::println("window size:{},{}",event->size().width(),event->size().height());
}

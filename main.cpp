#include "garden.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLayout>
#include <qnamespace.h>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow window;
  Garden *garden = new Garden(&window);
  window.setCentralWidget(garden);
  window.resize(500, 500);

  window.show();
  return a.exec();
}

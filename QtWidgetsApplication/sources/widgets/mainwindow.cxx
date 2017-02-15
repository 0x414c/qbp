#include "mainwindow.hxx"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QEvent>
#include <QMainWindow>
#include <QMessageBox>
#include <QWidget>

#include "../constants.hxx"
#include "../definitions.hxx"


namespace Widgets
{
  MainWindow::MainWindow (QWidget * parent) :
    QMainWindow (parent),
    ui_ (new Ui::MainWindow)
  {
    ui_->setupUi (this);

    setDefaults ();
  }


  MainWindow::~MainWindow (void)
  {
    delete ui_;
  }


  void
  MainWindow::setDefaults (void)
  {
    using namespace Constants::Gui;


    setWindowTitle (WindowTitle);
    setWindowFilePath (FilePath);
    setWindowModified (true);
  }


  void
  MainWindow::changeEvent (QEvent * event)
  {
    QMainWindow::changeEvent (event);

    switch (event->type ())
    {
      case QEvent::LanguageChange:
      {
        ui_->retranslateUi (this);

        break;
      }

      default:
      {
        break;
      }
    }
  }


  void
  MainWindow::on_action_Quit_triggered (void)
  {
    QApplication::quit ();
  }


  // TODO: !~ Move help text to separate file `help.inc'.
  void
  MainWindow::on_action_AboutApplication_triggered (void)
  {
    QMessageBox::about (
      this,
      QStringLiteral ("About Application"),
      QStringLiteral (
        "<h3><b>"
        __QBP_DEFINE_PREFIX___APP_NAME
        " ver. "
        __QBP_DEFINE_PREFIX___APP_VERSION
        "</b></h3>"
        "Build date: "
        __QBP_DEFINE_PREFIX___APP_BUILD_DATE
        "<br>"
        "Build time: "
        __QBP_DEFINE_PREFIX___APP_BUILD_TIME
        "<br><br>"
        __QBP_DEFINE_PREFIX___APP_DESCRIPTION
        "<hr>"
        "This software uses:"
        "<ul>"
        "<li><a href=\"http://www.qt.io/\">Qt (ver. "
        __QBP_DEFINE_PREFIX___QT_VERSION
        ")</a></li>"
        "<li><a href=\"http://api.kde.org/frameworks/breeze-icons/html/\">"
        "Breeze Icons (ver. "
        __QBP_DEFINE_PREFIX___BREEZE_ICONS_VERSION
        ")</a> "
        "by the <a href=\"http://www.kde.org/\">KDE® Community</a></li>"
        "</ul>"
        "<hr>"
        __QBP_DEFINE_PREFIX___APP_COPYRIGHT
        "<br><br>"
        "This program is free software: you can redistribute it and/or modify "
        "it under the terms of the GNU General Public License as published by "
        "the Free Software Foundation, either version 3 of the License, or "
        "(at your option) any later version."
        "<br><br>"
        "This program is distributed in the hope that it will be useful, "
        "but WITHOUT ANY WARRANTY; without even the implied warranty of "
        "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the "
        "GNU General Public License for more details."
        "<br><br>"
        "You should have received a copy of the GNU General Public License "
        "along with this program.  If not, see "
        "<a href=\"https://www.gnu.org/licenses/\">"
        "Licenses - GNU Project - Free Software Foundation</a>."
      )
    );
  }


  void
  MainWindow::on_action_AboutQt_triggered (void)
  {
    QApplication::aboutQt ();
  }
}

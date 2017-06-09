#pragma once

#ifndef __QBP_MACRO_PREFIX___WIDGETS_MAINWINDOW_HXX
#define __QBP_MACRO_PREFIX___WIDGETS_MAINWINDOW_HXX


#include <QEvent>
#include <QMainWindow>
#include <QWidget>


namespace Ui
{
  class MainWindow;
}


namespace Widgets
{
  class MainWindow :
    public QMainWindow
  {
    Q_OBJECT


    public:
      explicit MainWindow (QWidget * parent = nullptr);

      ~MainWindow (void);


    protected:
      virtual void changeEvent (QEvent * event) override;


    private Q_SLOTS:
      void on_quit_action_triggered (void);

      void on_about_application_action_triggered (void);

      void on_about_qt_action_triggered (void);


    private:
      void configure_ (void);


      Ui::MainWindow * ui_ = nullptr;
  };
}


#endif // __QBP_MACRO_PREFIX___WIDGETS_MAINWINDOW_HXX

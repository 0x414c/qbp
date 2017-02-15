#pragma once

#ifndef __QBP_DEFINE_PREFIX___WIDGETS_MAINWINDOW_HXX
#define __QBP_DEFINE_PREFIX___WIDGETS_MAINWINDOW_HXX


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

      void setDefaults (void);


    protected:
      virtual void changeEvent (QEvent * event) override;


    private Q_SLOTS:
      void on_action_Quit_triggered (void);

      void on_action_AboutApplication_triggered (void);
      void on_action_AboutQt_triggered (void);


    private:
      Ui::MainWindow * ui_;
  };
}


#endif // __QBP_DEFINE_PREFIX___WIDGETS_MAINWINDOW_HXX

#pragma once

#ifndef __QBP_DEFINE_PREFIX___UTILS_APPLICATION_HXX
#define __QBP_DEFINE_PREFIX___UTILS_APPLICATION_HXX


#include <QApplication>


namespace Utils
{
  /**
   * @brief makeApplication
   * @param argc
   * @param argv
   * @return
   */
  QApplication * makeApplication (int & argc, char ** argv);
}


#endif // __QBP_DEFINE_PREFIX___UTILS_APPLICATION_HXX

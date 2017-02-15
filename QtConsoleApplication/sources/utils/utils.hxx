#pragma once

#ifndef __QBP_DEFINE_PREFIX_UTILS_HXX
#define __QBP_DEFINE_PREFIX_UTILS_HXX


#include <QCoreApplication>


namespace Utils
{
  QCoreApplication * makeApplication (int & argc, char ** argv);
}


#endif // __QBP_DEFINE_PREFIX_UTILS_HXX

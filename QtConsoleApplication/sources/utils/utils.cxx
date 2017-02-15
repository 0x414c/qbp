#include "utils.hxx"

#include <QCoreApplication>

#include "../constants.hxx"


namespace Utils
{
  QCoreApplication *
  makeApplication (int & argc, char ** argv)
  {
    using namespace Constants::Application;


    QCoreApplication * const application (new QCoreApplication (argc, argv));

    QCoreApplication::setApplicationName (Name);
    QCoreApplication::setApplicationVersion (Version);
    QCoreApplication::setOrganizationName (OrgName);
    QCoreApplication::setOrganizationDomain (OrgDomain);

    return application;
  }
}

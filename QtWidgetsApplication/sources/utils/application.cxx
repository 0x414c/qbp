#include "application.hxx"

#include <QApplication>

#include "../constants.hxx"


namespace Utils
{
  QApplication *
  makeApplication (int & argc, char ** argv)
  {
    using namespace Constants::Application;


    QApplication * const application (new QApplication (argc, argv));

    QCoreApplication::setApplicationName (Name);
    QCoreApplication::setApplicationVersion (Version);
    QCoreApplication::setOrganizationName (OrgName);
    QCoreApplication::setOrganizationDomain (OrgDomain);
    QApplication::setApplicationDisplayName (DisplayName);

    return application;
  }
}

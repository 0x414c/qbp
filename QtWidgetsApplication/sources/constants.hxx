#pragma once

#ifndef __QBP_DEFINE_PREFIX___CONSTANTS_HXX
#define __QBP_DEFINE_PREFIX___CONSTANTS_HXX


#include <QLocale>
#include <QString>


namespace Constants
{
  namespace Application
  {
    const QString Name (QStringLiteral ("__QBP_APP_NAME__"));
    const QString Version (QStringLiteral ("__QBP_APP_VERSION__"));
    const QString OrgName (QStringLiteral ("__QBP_ORG_NAME__"));
    const QString OrgDomain (QStringLiteral ("__QBP_ORG_DOMAIN__"));
    const QString DisplayName (Name);
    const QString Description (QStringLiteral ("__QBP_APP_DESCRIPTION__"));

    // NOTE: Identifier format is: [language[_territory][.codeset][@modifier]]
    constexpr const char * const LocaleIdentifier ("en_US.UTF-8");
    const QLocale Locale (LocaleIdentifier);

    constexpr bool IsDesktopSettingsAware (true);
  }


  namespace Gui
  {
    const QString WindowTitle (QStringLiteral (""));
    const QString FilePath (QStringLiteral ("Untitled"));
  }
}


#endif // __QBP_DEFINE_PREFIX___CONSTANTS_HXX

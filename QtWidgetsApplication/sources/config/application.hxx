#pragma once

#ifndef __QBP_MACRO_PREFIX___CONFIG_APPLICATION_HXX
#define __QBP_MACRO_PREFIX___CONFIG_APPLICATION_HXX


#include <QLocale>
#include <QString>

#include "../definitions.hxx"


namespace Config
{
  namespace Application
  {
    const QString Name (QStringLiteral (__QBP_MACRO_PREFIX___APP_NAME));
    const QString Version (QStringLiteral (__QBP_MACRO_PREFIX___APP_VERSION));
    const QString Org_name (QStringLiteral (__QBP_MACRO_PREFIX___ORG_NAME));
    const QString Org_domain (QStringLiteral (__QBP_MACRO_PREFIX___ORG_DOMAIN));
    const QString Display_name (QStringLiteral (__QBP_MACRO_PREFIX___APP_DISPLAY_NAME));

    // NOTE: Identifier format is: [language[_territory][.codeset][@modifier]]
    constexpr const char Locale_identifier[] ("en_US.UTF-8");
    const QLocale Locale (Locale_identifier);

    constexpr bool Is_desktop_settings_aware (true);
  }
}


#endif // __QBP_MACRO_PREFIX___CONFIG_APPLICATION_HXX

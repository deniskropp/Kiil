/*
    SPDX-FileCopyrightText: %{CURRENT_YEAR} %{AUTHOR} <%{EMAIL}>

    SPDX-License-Identifier: LGPL-2.1-or-later
*/

#include "kiilrunner.h"

#include <KLocalizedString>

KiilRunner::KiilRunner(QObject *parent, const KPluginMetaData &data)
    : KRunner::AbstractRunner(parent, data)
{
    // Disallow short queries
    setMinLetterCount(3);
    // Provide usage help for this plugin
    addSyntax(QStringLiteral("sometriggerword :q:"), i18n("Description for this syntax"));
}

void KiilRunner::match(KRunner::RunnerContext &context)
{
    const QString term = context.query();
    if (term.compare(QLatin1String("hello"), Qt::CaseInsensitive) == 0) {
        KRunner::QueryMatch match(this);
        match.setText(i18n("Hello from KiilRunner"));
        context.addMatch(match);
    }
}

void KiilRunner::run(const KRunner::RunnerContext &context, const KRunner::QueryMatch &match)
{
    Q_UNUSED(context)
    Q_UNUSED(match)

    // TODO
}

K_PLUGIN_CLASS_WITH_JSON(KiilRunner, "kiilrunner.json")

// needed for the QObject subclass declared as part of K_PLUGIN_CLASS_WITH_JSON
#include "kiilrunner.moc"

#include "moc_kiilrunner.cpp"

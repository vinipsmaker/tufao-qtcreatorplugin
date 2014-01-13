/*  This file is part of the Tufão project
    Copyright (C) 2012, 2013 Vinícius dos Santos Oliveira <vini.ipsmaker@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any
    later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "tufaoplugin.h"
#include "tufaowizard.h"

#include <QtCore/QtPlugin>
#include <QIcon>

using namespace Tufao;

TufaoPlugin::TufaoPlugin()
{
}

TufaoPlugin::~TufaoPlugin()
{
}

bool TufaoPlugin::initialize(const QStringList &arguments, QString *errorString)
{
    Q_UNUSED(arguments)
    Q_UNUSED(errorString)

    addAutoReleasedObject(new TufaoWizard(this));
    
    return true;
}

void TufaoPlugin::extensionsInitialized()
{
}

ExtensionSystem::IPlugin::ShutdownFlag TufaoPlugin::aboutToShutdown()
{
    return SynchronousShutdown;
}

#if !(QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
Q_EXPORT_PLUGIN2(Tufao, TufaoPlugin)
#endif

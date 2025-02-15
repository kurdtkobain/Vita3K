// Vita3K emulator project
// Copyright (C) 2021 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <module/module.h>

enum SceFiosErrorCode {
    SCE_FIOS_OK = 0
};

typedef SceUID SceFiosOverlayID;

enum SceFiosOverlayResolveMode {
    SCE_FIOS_OVERLAY_RESOLVE_FOR_READ = 0,
    SCE_FIOS_OVERLAY_RESOLVE_FOR_WRITE = 1
};

BRIDGE_DECL(sceFiosOverlayAddForProcess02)
BRIDGE_DECL(sceFiosOverlayGetInfoForProcess02)
BRIDGE_DECL(sceFiosOverlayGetList02)
BRIDGE_DECL(sceFiosOverlayGetRecommendedScheduler02)
BRIDGE_DECL(sceFiosOverlayModifyForProcess02)
BRIDGE_DECL(sceFiosOverlayRemoveForProcess02)
BRIDGE_DECL(sceFiosOverlayResolveSync02)
BRIDGE_DECL(sceFiosOverlayResolveWithRangeSync02)
BRIDGE_DECL(sceFiosOverlayThreadIsDisabled02)
BRIDGE_DECL(sceFiosOverlayThreadSetDisabled02)

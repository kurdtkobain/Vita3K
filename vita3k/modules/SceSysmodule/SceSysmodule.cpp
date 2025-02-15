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

#include "SceSysmodule.h"

#include <module/load_module.h>
#include <modules/module_parent.h>
#include <util/tracy.h>

TRACY_MODULE_NAME(SceSysmodule);

template <>
std::string to_debug_str<SceSysmoduleModuleId>(const MemState &mem, SceSysmoduleModuleId mode) {
    switch (mode) {
    case SCE_SYSMODULE_INVALID: return "SCE_SYSMODULE_INVALID";
    case SCE_SYSMODULE_NET: return "SCE_SYSMODULE_NET";
    case SCE_SYSMODULE_HTTP: return "SCE_SYSMODULE_HTTP";
    case SCE_SYSMODULE_SSL: return "SCE_SYSMODULE_SSL";
    case SCE_SYSMODULE_HTTPS: return "SCE_SYSMODULE_HTTPS";
    case SCE_SYSMODULE_PERF: return "SCE_SYSMODULE_PERF";
    case SCE_SYSMODULE_FIBER: return "SCE_SYSMODULE_FIBER";
    case SCE_SYSMODULE_ULT: return "SCE_SYSMODULE_ULT";
    case SCE_SYSMODULE_DBG: return "SCE_SYSMODULE_DBG";
    case SCE_SYSMODULE_RAZOR_CAPTURE: return "SCE_SYSMODULE_RAZOR_CAPTURE";
    case SCE_SYSMODULE_RAZOR_HUD: return "SCE_SYSMODULE_RAZOR_HUD";
    case SCE_SYSMODULE_NGS: return "SCE_SYSMODULE_NGS";
    case SCE_SYSMODULE_SULPHA: return "SCE_SYSMODULE_SULPHA";
    case SCE_SYSMODULE_SAS: return "SCE_SYSMODULE_SAS";
    case SCE_SYSMODULE_PGF: return "SCE_SYSMODULE_PGF";
    case SCE_SYSMODULE_APPUTIL: return "SCE_SYSMODULE_APPUTIL";
    case SCE_SYSMODULE_FIOS2: return "SCE_SYSMODULE_FIOS2";
    case SCE_SYSMODULE_IME: return "SCE_SYSMODULE_IME";
    case SCE_SYSMODULE_NP_BASIC: return "SCE_SYSMODULE_NP_BASIC";
    case SCE_SYSMODULE_SYSTEM_GESTURE: return "SCE_SYSMODULE_SYSTEM_GESTURE";
    case SCE_SYSMODULE_LOCATION: return "SCE_SYSMODULE_LOCATION";
    case SCE_SYSMODULE_NP: return "SCE_SYSMODULE_NP";
    case SCE_SYSMODULE_PHOTO_EXPORT: return "SCE_SYSMODULE_PHOTO_EXPORT";
    case SCE_SYSMODULE_XML: return "SCE_SYSMODULE_XML";
    case SCE_SYSMODULE_NP_COMMERCE2: return "SCE_SYSMODULE_NP_COMMERCE2";
    case SCE_SYSMODULE_NP_UTILITY: return "SCE_SYSMODULE_NP_UTILITY";
    case SCE_SYSMODULE_VOICE: return "SCE_SYSMODULE_VOICE";
    case SCE_SYSMODULE_VOICEQOS: return "SCE_SYSMODULE_VOICEQOS";
    case SCE_SYSMODULE_NP_MATCHING2: return "SCE_SYSMODULE_NP_MATCHING2";
    case SCE_SYSMODULE_SCREEN_SHOT: return "SCE_SYSMODULE_SCREEN_SHOT";
    case SCE_SYSMODULE_NP_SCORE_RANKING: return "SCE_SYSMODULE_NP_SCORE_RANKING";
    case SCE_SYSMODULE_SQLITE: return "SCE_SYSMODULE_SQLITE";
    case SCE_SYSMODULE_TRIGGER_UTIL: return "SCE_SYSMODULE_TRIGGER_UTIL";
    case SCE_SYSMODULE_RUDP: return "SCE_SYSMODULE_RUDP";
    case SCE_SYSMODULE_CODECENGINE_PERF: return "SCE_SYSMODULE_CODECENGINE_PERF";
    case SCE_SYSMODULE_LIVEAREA: return "SCE_SYSMODULE_LIVEAREA";
    case SCE_SYSMODULE_NP_ACTIVITY: return "SCE_SYSMODULE_NP_ACTIVITY";
    case SCE_SYSMODULE_NP_TROPHY: return "SCE_SYSMODULE_NP_TROPHY";
    case SCE_SYSMODULE_NP_MESSAGE: return "SCE_SYSMODULE_NP_MESSAGE";
    case SCE_SYSMODULE_SHUTTER_SOUND: return "SCE_SYSMODULE_SHUTTER_SOUND";
    case SCE_SYSMODULE_CLIPBOARD: return "SCE_SYSMODULE_CLIPBOARD";
    case SCE_SYSMODULE_NP_PARTY: return "SCE_SYSMODULE_NP_PARTY";
    case SCE_SYSMODULE_NET_ADHOC_MATCHING: return "SCE_SYSMODULE_NET_ADHOC_MATCHING";
    case SCE_SYSMODULE_NEAR_UTIL: return "SCE_SYSMODULE_NEAR_UTIL";
    case SCE_SYSMODULE_NP_TUS: return "SCE_SYSMODULE_NP_TUS";
    case SCE_SYSMODULE_MP4: return "SCE_SYSMODULE_MP4";
    case SCE_SYSMODULE_AACENC: return "SCE_SYSMODULE_AACENC";
    case SCE_SYSMODULE_HANDWRITING: return "SCE_SYSMODULE_HANDWRITING";
    case SCE_SYSMODULE_ATRAC: return "SCE_SYSMODULE_ATRAC";
    case SCE_SYSMODULE_NP_SNS_FACEBOOK: return "SCE_SYSMODULE_NP_SNS_FACEBOOK";
    case SCE_SYSMODULE_VIDEO_EXPORT: return "SCE_SYSMODULE_VIDEO_EXPORT";
    case SCE_SYSMODULE_NOTIFICATION_UTIL: return "SCE_SYSMODULE_NOTIFICATION_UTIL";
    case SCE_SYSMODULE_BG_APP_UTIL: return "SCE_SYSMODULE_BG_APP_UTIL";
    case SCE_SYSMODULE_INCOMING_DIALOG: return "SCE_SYSMODULE_INCOMING_DIALOG";
    case SCE_SYSMODULE_IPMI: return "SCE_SYSMODULE_IPMI";
    case SCE_SYSMODULE_AUDIOCODEC: return "SCE_SYSMODULE_AUDIOCODEC";
    case SCE_SYSMODULE_FACE: return "SCE_SYSMODULE_FACE";
    case SCE_SYSMODULE_SMART: return "SCE_SYSMODULE_SMART";
    case SCE_SYSMODULE_MARLIN: return "SCE_SYSMODULE_MARLIN";
    case SCE_SYSMODULE_MARLIN_DOWNLOADER: return "SCE_SYSMODULE_MARLIN_DOWNLOADER";
    case SCE_SYSMODULE_MARLIN_APP_LIB: return "SCE_SYSMODULE_MARLIN_APP_LIB";
    case SCE_SYSMODULE_TELEPHONY_UTIL: return "SCE_SYSMODULE_TELEPHONY_UTIL";
    case SCE_SYSMODULE_PSPNET_ADHOC: return "SCE_SYSMODULE_PSPNET_ADHOC";
    case SCE_SYSMODULE_DTCP_IP: return "SCE_SYSMODULE_DTCP_IP";
    case SCE_SYSMODULE_VIDEO_SEARCH_EMPR: return "SCE_SYSMODULE_VIDEO_SEARCH_EMPR";
    case SCE_SYSMODULE_NP_SIGNALING: return "SCE_SYSMODULE_NP_SIGNALING";
    case SCE_SYSMODULE_BEISOBMF: return "SCE_SYSMODULE_BEISOBMF";
    case SCE_SYSMODULE_BEMP2SYS: return "SCE_SYSMODULE_BEMP2SYS";
    case SCE_SYSMODULE_MUSIC_EXPORT: return "SCE_SYSMODULE_MUSIC_EXPORT";
    case SCE_SYSMODULE_NEAR_DIALOG_UTIL: return "SCE_SYSMODULE_NEAR_DIALOG_UTIL";
    case SCE_SYSMODULE_LOCATION_EXTENSION: return "SCE_SYSMODULE_LOCATION_EXTENSION";
    case SCE_SYSMODULE_AVPLAYER: return "SCE_SYSMODULE_AVPLAYER";
    case SCE_SYSMODULE_GAME_UPDATE: return "SCE_SYSMODULE_GAME_UPDATE";
    case SCE_SYSMODULE_MAIL_API: return "SCE_SYSMODULE_MAIL_API";
    case SCE_SYSMODULE_TELEPORT_CLIENT: return "SCE_SYSMODULE_TELEPORT_CLIENT";
    case SCE_SYSMODULE_TELEPORT_SERVER: return "SCE_SYSMODULE_TELEPORT_SERVER";
    case SCE_SYSMODULE_MP4_RECORDER: return "SCE_SYSMODULE_MP4_RECORDER";
    case SCE_SYSMODULE_APPUTIL_EXT: return "SCE_SYSMODULE_APPUTIL_EXT";
    case SCE_SYSMODULE_NP_WEBAPI: return "SCE_SYSMODULE_NP_WEBAPI";
    case SCE_SYSMODULE_AVCDEC: return "SCE_SYSMODULE_AVCDEC";
    case SCE_SYSMODULE_JSON: return "SCE_SYSMODULE_JSON";
    }
    return std::to_string(mode);
}

static bool is_modules_enable(EmuEnvState &emuenv, SceSysmoduleModuleId module_id) {
    if (emuenv.cfg.current_config.modules_mode == ModulesMode::MANUAL)
        return !emuenv.cfg.current_config.lle_modules.empty() && is_lle_module(module_id, emuenv);
    else
        return is_lle_module(module_id, emuenv);
}

EXPORT(int, sceSysmoduleIsLoaded, SceSysmoduleModuleId module_id) {
    TRACY_FUNC(sceSysmoduleIsLoaded, module_id);
    if (module_id < 0 || module_id > SYSMODULE_COUNT)
        return SCE_SYSMODULE_ERROR_INVALID_VALUE;

    if (is_modules_enable(emuenv, module_id)) {
        if (is_module_loaded(emuenv.kernel, module_id))
            return SCE_SYSMODULE_LOADED;
        else
            return SCE_SYSMODULE_ERROR_UNLOADED;
    } else
        return SCE_SYSMODULE_LOADED;
}

EXPORT(int, sceSysmoduleIsLoadedInternal) {
    TRACY_FUNC(sceSysmoduleIsLoadedInternal);
    return UNIMPLEMENTED();
}

EXPORT(int, sceSysmoduleLoadModule, SceSysmoduleModuleId module_id) {
    TRACY_FUNC(sceSysmoduleLoadModule, module_id);
    if (module_id < 0 || module_id > SYSMODULE_COUNT)
        return SCE_SYSMODULE_ERROR_INVALID_VALUE;

    if (is_modules_enable(emuenv, module_id)) {
        if (load_module(emuenv, thread_id, module_id))
            return SCE_SYSMODULE_LOADED;
        else
            return SCE_SYSMODULE_ERROR_UNLOADED;
    } else
        return SCE_SYSMODULE_LOADED;
}

EXPORT(int, sceSysmoduleLoadModuleInternal) {
    TRACY_FUNC(sceSysmoduleLoadModuleInternal);
    return UNIMPLEMENTED();
}

EXPORT(int, sceSysmoduleLoadModuleInternalWithArg) {
    TRACY_FUNC(sceSysmoduleLoadModuleInternalWithArg);
    return UNIMPLEMENTED();
}

EXPORT(int, sceSysmoduleUnloadModule) {
    TRACY_FUNC(sceSysmoduleUnloadModule);
    return UNIMPLEMENTED();
}

EXPORT(int, sceSysmoduleUnloadModuleInternal) {
    TRACY_FUNC(sceSysmoduleUnloadModuleInternal);
    return UNIMPLEMENTED();
}

EXPORT(int, sceSysmoduleUnloadModuleInternalWithArg) {
    TRACY_FUNC(sceSysmoduleUnloadModuleInternalWithArg);
    return UNIMPLEMENTED();
}

BRIDGE_IMPL(sceSysmoduleIsLoaded)
BRIDGE_IMPL(sceSysmoduleIsLoadedInternal)
BRIDGE_IMPL(sceSysmoduleLoadModule)
BRIDGE_IMPL(sceSysmoduleLoadModuleInternal)
BRIDGE_IMPL(sceSysmoduleLoadModuleInternalWithArg)
BRIDGE_IMPL(sceSysmoduleUnloadModule)
BRIDGE_IMPL(sceSysmoduleUnloadModuleInternal)
BRIDGE_IMPL(sceSysmoduleUnloadModuleInternalWithArg)

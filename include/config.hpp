#pragma once

#include <filesystem>
#include <vector>

struct Config {
    /// @brief whether to apply note colors from diffs
    bool customSongNoteColors = true;
    /// @brief whether to apply obstacle colors from diffs
    bool customSongObstacleColors = true;
    /// @brief whether to apply environment colors from diffs
    bool customSongEnvironmentColors = true;

    /// @brief whether the saber count override should be honored
    bool disableOneSaberOverride = false;

    /// @brief path to the preferred folder where to store songs. This is exposed to people consuming the api as a getter
    std::filesystem::path PreferredCustomLevelPath = "/sdcard/ModData/com.beatgames.beatsaber/Mods/SongCore/CustomLevels";
    /// @brief multiple paths to folders to load songs from, in case user has multiple folders. Not exposed
    std::vector<std::filesystem::path> RootCustomLevelPaths {
        "/sdcard/ModData/com.beatgames.beatsaber/Mods/SongCore/CustomLevels",
        "/sdcard/ModData/com.beatgames.beatsaber/Mods/SongLoader/CustomLevels"
    };

    /// @brief path to the preferred folder where to store WIP songs. This is exposed to people consuming the api as a getter
    std::filesystem::path PreferredCustomWIPLevelPath = "/sdcard/ModData/com.beatgames.beatsaber/Mods/SongCore/CustomWIPLevels";
    /// @brief multiple paths to folders to load WIP songs from, in case user has multiple folders. Not exposed
    std::vector<std::filesystem::path> RootCustomWIPLevelPaths {
        "/sdcard/ModData/com.beatgames.beatsaber/Mods/SongCore/CustomWIPLevels",
        "/sdcard/ModData/com.beatgames.beatsaber/Mods/SongLoader/CustomWIPLevels"
    };
};

extern Config config;

void SaveConfig();
bool LoadConfig();
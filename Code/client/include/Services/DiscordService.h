#pragma once

#include <discord_game_sdk.h>

class DiscordService final : public entt::registry
{
  public:
    DiscordService(entt::dispatcher&);
    ~DiscordService();

    bool Init();

    // noop currently
    void Update();

    bool IsCanaryDiscord();

    // update the presence state
    // then request an update
    inline auto &GetPresence()
    {
        return m_ActivityState;
    }
    void UpdatePresence(bool newTimeStamp);

    void WndProcHandler(HWND, UINT, WPARAM, LPARAM);
  private:
    void InitOverlay(struct IDXGISwapChain *);
    void OnLocationChangeEvent() noexcept;

    entt::scoped_connection m_cellChangeConnection;

    bool m_bCustomPresence = false;
    bool m_bOverlayEnabled = false;
    bool m_bRequestThreadKillHack = false;

    IDiscordCore *m_pCore = nullptr;
    IDiscordUserManager *m_pUserMgr = nullptr;
    IDiscordActivityManager *m_pActivity = nullptr;
    IDiscordApplicationManager *m_pAppMgr = nullptr;
    IDiscordOverlayManager *m_pOverlayMgr = nullptr;
    DiscordUserId m_UserId = 0;
    DiscordActivity m_ActivityState{};

    uint32_t m_lastLocationId = 0;
    uint32_t m_lastWorldspaceId = 0;
};

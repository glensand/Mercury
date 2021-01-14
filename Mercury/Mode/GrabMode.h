#pragma once
#include "ModeBase.h"

namespace merc
{

    class GrabMode final : public ModeBase
    {
    public:
        GrabMode(GameInterface& gameInterface);

        virtual ~GrabMode() = default;

        virtual void OnFrame() override;

        bool check_collector_move(std::vector<std::vector<Cell>>, size_t, size_t, size_t, size_t size_t, size_t, bool);
        bool check_sapper_move(std::vector<std::vector<Cell>>, size_t, size_t, size_t, size_t size_t, size_t, bool);

        std::vector<Direction> find_way_collector();
        std::vector<Direction> find_way_sapper();

        bool apples_on_map();
        bool bombs_on_map();
        bool move_collector(Direction m);
        bool move_collector(Direction m);

        void auto_grab();

    };

}

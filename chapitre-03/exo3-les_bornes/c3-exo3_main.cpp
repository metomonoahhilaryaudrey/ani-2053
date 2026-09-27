
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"

int nkmain(const nkentseu::NkEntryState& state) {

    nkentseu::NkWindowConfig cfg;
    cfg.title = "MonTitre, etape 02";
    cfg.minWidth = 450;
    cfg.minHeight = 300;

    nkentseu::NkWindow window;

    if (!window.Create(cfg)) {
        logger.Error("Failed to create window");
        return -1;
    }

    bool running = true;

    while (running) {

        nkentseu::NkEvent* event = nullptr;

        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr) {

            // Process events
            if (event->Is<nkentseu::NkWindowCloseEvent>()) {

                auto size = window.GetSize();

                logger.Info("X = {}", size.x);
                logger.Info("Y = {}", size.y);

                running = false;
            }
        }
    }

    return 0;
}


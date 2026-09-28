
#include "NKWindow/NKMain.h"
#include "NKWindow/NKWindow.h"
#include <string>

static std::string ConstruireTitre(bool modifie, int w, int h)
{
    return std::string("notes.txt")
         + (modifie ? "*" : "")
         + " - "
         + std::to_string(w)
         + "x"
         + std::to_string(h);
}

int nkmain(const nkentseu::NkEntryState& state)
{
    nkentseu::NkWindowConfig cfg;

    cfg.title = "devoir.txt - 1280x720";
    cfg.width = 1280;
    cfg.height = 720;

    nkentseu::NkWindow window;

    if (!window.Create(cfg))
    {
        logger.Error("Failed to create window");
        return -1;
    }

    bool running = true;
    bool modifie = false;

    while (running)
    {
        nkentseu::NkEvent* event = nullptr;

        while ((event = nkentseu::NkEvents().PollEvent()) != nullptr)
        {
            
            if (event->Is<nkentseu::NkWindowCloseEvent>())
            {
                auto size = window.GetSize();

                logger.Info("X = {}", size.x);
                logger.Info("Y = {}", size.y);

                running = false;
            }

    
            else if (event->Is<nkentseu::NkKeyPressEvent>())
            {
                if (!modifie)
                {
                    modifie = true;

                    auto size = window.GetSize();

                    std::string titre =
                        ConstruireTitre(modifie, size.x, size.y);

                    
                    window.SetTitle(titre.c_str());
                }
            }
        }
    }

    return 0;
}

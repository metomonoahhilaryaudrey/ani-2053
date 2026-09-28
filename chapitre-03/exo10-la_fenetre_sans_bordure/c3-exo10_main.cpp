#include "NKWindow/NKWindow.h"
#include "NKWindow/NKMain.h"
#include "NKEvent/NkEventDispatcher.h"

using namespace nkentseu;


static const int32 TITLE_BAR_HEIGHT = 32;

static const int32 BUTTON_WIDTH = 40;

enum class TitleBarZone {
	None,
	Drag, 
	Minimize,
	MaximizeRestore,
	Close
};


static TitleBarZone ZoneAt(int32 x, int32 y, uint32 windowWidth) {
	if (y < 0 || y >= TITLE_BAR_HEIGHT) {
		return TitleBarZone::None;
	}

	int32 closeLeft    = static_cast<int32>(windowWidth) - BUTTON_WIDTH;
	int32 maximizeLeft = closeLeft - BUTTON_WIDTH;
	int32 minimizeLeft = maximizeLeft - BUTTON_WIDTH;

	if (x >= closeLeft) return TitleBarZone::Close;
	if (x >= maximizeLeft) return TitleBarZone::MaximizeRestore;
	if (x >= minimizeLeft) return TitleBarZone::Minimize;

	return TitleBarZone::Drag;
}

int nkmain(const NkEntryState &state) {
	NkWindowConfig cfg;
	cfg.title  = "Exercice 10 - Fenetre sans bordure";
	cfg.width  = 850;
	cfg.height = 600;
	cfg.frame  = false; // <-- fenetre sans bordure : on gere tout nous-memes

	NkWindow window(cfg);
	if (!window.IsOpen()) {
		logger.Error("[exo10] creation fenetre echouee");
		return -1;
	}
	window.SetTitle("Ma barre de titre a moi");


	bool dragging = false;
	math::NkVec2u dragWindowStart(0, 0); 
	int32 dragMouseStartScreenX = 0, dragMouseStartScreenY = 0;

	logger.Info("[exo10] barre de titre custom active : glissez pour deplacer, "
				"double-cliquez pour agrandir/restaurer");

	while (window.IsOpen()) {
		NkEvent *ev;
		while (NkEvents().PollEvent(ev)) {
			if (ev->Is<NkWindowCloseEvent>()) {
				window.Close();
				break;
			}

			
			if (auto *press = ev->As<NkMouseButtonPressEvent>()) {
				if (press->IsLeft()) {
					TitleBarZone zone = ZoneAt(press->GetX(), press->GetY(), window.GetSize().x);

					switch (zone) {
						case TitleBarZone::Close:
							window.Close();
							break;

						case TitleBarZone::Minimize:
							window.Minimize();
							break;

						case TitleBarZone::MaximizeRestore:
							if (window.IsMaximized()) window.Restore();
							else window.Maximize();
							break;

						case TitleBarZone::Drag:
							dragging = true;
							dragWindowStart = window.GetPosition();
							dragMouseStartScreenX = press->GetScreenX();
							dragMouseStartScreenY = press->GetScreenY();
							break;

						default:
							break;
					}
				}
			}

			
			if (auto *release = ev->As<NkMouseButtonReleaseEvent>()) {
				if (release->IsLeft()) {
					dragging = false;
				}
			}

			
			if (auto *move = ev->As<NkMouseMoveEvent>()) {
				if (dragging) {
					int32 deltaX = move->GetScreenX() - dragMouseStartScreenX;
					int32 deltaY = move->GetScreenY() - dragMouseStartScreenY;
					window.SetPosition(static_cast<int32>(dragWindowStart.x) + deltaX,
										static_cast<int32>(dragWindowStart.y) + deltaY);
				}
			}

		
			if (auto *dbl = ev->As<NkMouseDoubleClickEvent>()) {
				if (dbl->IsLeft()) {
					TitleBarZone zone = ZoneAt(dbl->GetX(), dbl->GetY(), window.GetSize().x);
					if (zone == TitleBarZone::Drag) {
						if (window.IsMaximized()) window.Restore();
						else window.Maximize();
					}
				}
			}
		}
	}

	return 0;
}
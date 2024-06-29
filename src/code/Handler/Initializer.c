#include "../../header/Handler/initializer.h"
#include <ctype.h>
#include <string.h>

void initializer(App *app) {
    loadFile(app, "data/default.txt");
}

void clearApp(App *app) {
    memset(app, 0, sizeof(*app));
}

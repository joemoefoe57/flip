#pragma once

#include "view.h"
#include <furi.h>

typedef struct {
    void* data;
    osMutexId_t mutex;
} ViewModelLocking;

struct View {
    ViewDrawCallback draw_callback;
    ViewInputCallback input_callback;

    ViewModelType model_type;
    ViewNavigationCallback previous_callback;
    ViewNavigationCallback next_callback;
    ViewCallback enter_callback;
    ViewCallback exit_callback;

    ViewUpdateCallback update_callback;
    void* update_callback_context;

    void* model;
    void* context;
};

/* Unlock model */
void view_unlock_model(View* view);

/* Draw Callback for View dispatcher */
void view_draw(View* view, Canvas* canvas);

/* Input Callback for View dispatcher */
bool view_input(View* view, InputEvent* event);

/* Previous Callback for View dispatcher */
uint32_t view_previous(View* view);

/* Next Callback for View dispatcher */
uint32_t view_next(View* view);

/* Enter Callback for View dispatcher */
void view_enter(View* view);

/* Exit Callback for View dispatcher */
void view_exit(View* view);

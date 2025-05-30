/**************************************************************************/
/*  debugger_editor_plugin.h                                              */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             REDOT ENGINE                               */
/*                        https://redotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2024-present Redot Engine contributors                   */
/*                                          (see REDOT_AUTHORS.md)        */
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#pragma once

#include "editor/plugins/editor_plugin.h"

class EditorFileServer;
class MenuButton;
class PopupMenu;
class RunInstancesDialog;

class DebuggerEditorPlugin : public EditorPlugin {
	GDCLASS(DebuggerEditorPlugin, EditorPlugin);

private:
	PopupMenu *debug_menu = nullptr;
	EditorFileServer *file_server = nullptr;
	RunInstancesDialog *run_instances_dialog = nullptr;

	enum MenuOptions {
		RUN_FILE_SERVER,
		RUN_LIVE_DEBUG,
		RUN_DEBUG_COLLISIONS,
		RUN_DEBUG_PATHS,
		RUN_DEBUG_NAVIGATION,
		RUN_DEBUG_AVOIDANCE,
		RUN_DEBUG_CANVAS_REDRAW,
		RUN_DEPLOY_REMOTE_DEBUG,
		RUN_RELOAD_SCRIPTS,
		SERVER_KEEP_OPEN,
		RUN_MULTIPLE_INSTANCES,
	};

	bool initializing = true;

	void _update_debug_options();
	void _notification(int p_what);
	void _menu_option(int p_option);

public:
	virtual String get_plugin_name() const override { return "Debugger"; }
	bool has_main_screen() const override { return false; }

	DebuggerEditorPlugin(PopupMenu *p_menu);
	~DebuggerEditorPlugin();
};

#!/usr/bin/python
from gi.repository import Gtk,Gio,Gdk,GObject

class MyWindow(Gtk.Window):

    def __init__(self):
    	self.click_counter = 0
        Gtk.Window.__init__(self, title="greeting")

        self.box = Gtk.Box(spacing=6)
        self.add(self.box)

        self.button1 = Gtk.Button(label='Hello')
        self.button1.connect("clicked",self.on_button1_clicked)
        self.box.pack_start(self.button1,True,True,0)

        self.button2 = Gtk.Button(label='Goodbye')
        self.button2.connect("clicked",self.on_button2_clicked)
        self.box.pack_start(self.button2,True,True,0)

        self.button = Gtk.Button(label="Click Here")
        self.btn_clk_signal_id=self.button.connect("clicked", self.on_button_clicked)
        self.box.pack_start(self.button,True,True,0)

    def on_button1_clicked(self,widget):
    	print("Hello")

    def on_button2_clicked(self,widget):
    	print('Goodbye')
    
    def on_button_clicked(self, widget):
    	self.click_counter += 1
    	print("Hello World" + ',' + str(self.click_counter))
    	if self.click_counter >= 5:
    		self.button.disconnect(self.btn_clk_signal_id)
    		print('disconnect')

class GridWindow(Gtk.Window):
	def __init__(self):
		Gtk.Window.__init__(self,title='Grid Example')

		grid=Gtk.Grid()
		self.add(grid)

		button1=Gtk.Button(label='Button1')
		button2=Gtk.Button(label='Button2')
		button3=Gtk.Button(label='Button3')
		button4=Gtk.Button(label='Button4')
		button5=Gtk.Button(label='Button5')
		button6=Gtk.Button(label='Button6')

		grid.add(button1)
		grid.attach(button2,1,0,2,1)
		grid.attach_next_to(button3,button1,Gtk.PositionType.BOTTOM,1,2)
		grid.attach_next_to(button4,button3,Gtk.PositionType.RIGHT,2,1)
		grid.attach(button5,1,2,1,1)
		grid.attach_next_to(button6,button5,Gtk.PositionType.RIGHT,1,1)

class TableWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Table Example")

        table = Gtk.Table(3, 3, True)
        self.add(table)

        button1 = Gtk.Button(label="Button 1")
        button2 = Gtk.Button(label="Button 2")
        button3 = Gtk.Button(label="Button 3")
        button4 = Gtk.Button(label="Button 4")
        button5 = Gtk.Button(label="Button 5")
        button6 = Gtk.Button(label="Button 6")

        table.attach(button1, 0, 1, 0, 1)
        table.attach(button2, 1, 3, 0, 1)
        table.attach(button3, 0, 1, 1, 3)
        table.attach(button4, 1, 3, 1, 2)
        table.attach(button5, 1, 2, 2, 3)
        table.attach(button6, 2, 3, 2, 3)

class ListBoxWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="ListBox Demo")
        self.set_border_width(10)

        hbox = Gtk.Box(spacing=6)
        self.add(hbox)

        listbox = Gtk.ListBox()
        listbox.set_selection_mode(Gtk.SelectionMode.NONE)
        hbox.pack_start(listbox, True, True, 0)

        row = Gtk.ListBoxRow()
        hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=50)
        row.add(hbox)
        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL)
        hbox.pack_start(vbox, True, True, 0)

        label1 = Gtk.Label("Automatic Date & Time", xalign=0)
        label2 = Gtk.Label("Requires internet access", xalign=0)
        vbox.pack_start(label1, True, True, 0)
        vbox.pack_start(label2, True, True, 0)

        switch = Gtk.Switch()
        switch.props.valign = Gtk.Align.CENTER
        hbox.pack_start(switch, False, True, 0)

        listbox.add(row)

        row = Gtk.ListBoxRow()
        hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=50)
        row.add(hbox)
        label = Gtk.Label("Enable Automatic Update", xalign=0)
        check = Gtk.CheckButton()
        hbox.pack_start(label, True, True, 0)
        hbox.pack_start(check, False, True, 0)

        listbox.add(row)

        row = Gtk.ListBoxRow()
        hbox = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL, spacing=50)
        row.add(hbox)
        label = Gtk.Label("Date Format", xalign=0)
        combo = Gtk.ComboBoxText()
        combo.insert(0, "0", "24-hour")
        combo.insert(1, "1", "AM/PM")
        hbox.pack_start(label, True, True, 0)
        hbox.pack_start(combo, False, True, 0)

        listbox.add(row)

class StackWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Stack Demo")
        self.set_border_width(10)

        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.add(vbox)

        stack = Gtk.Stack()
        stack.set_transition_type(Gtk.StackTransitionType.SLIDE_LEFT_RIGHT)
        stack.set_transition_duration(1000)
        
        checkbutton = Gtk.CheckButton("Click me!")
        stack.add_titled(checkbutton, "check", "Check Button")
        
        label = Gtk.Label()
        label.set_markup("<big>A fancy label</big>")
        stack.add_titled(label, "label", "A label")

        stack_switcher = Gtk.StackSwitcher()
        stack_switcher.set_stack(stack)
        vbox.pack_start(stack_switcher, True, True, 0)
        vbox.pack_start(stack, True, True, 0)

# Gio
class HeaderBarWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Stack Demo")
        self.set_border_width(10)
        self.set_default_size(400, 200)

        hb = Gtk.HeaderBar()
        hb.set_show_close_button(True)
        hb.props.title = "HeaderBar example"
        self.set_titlebar(hb)

        button = Gtk.Button()
        icon = Gio.ThemedIcon(name="mail-send-receive-symbolic")
        image = Gtk.Image.new_from_gicon(icon, Gtk.IconSize.BUTTON)
        button.add(image)
        hb.pack_end(button)
        
        box = Gtk.Box(orientation=Gtk.Orientation.HORIZONTAL)
        Gtk.StyleContext.add_class(box.get_style_context(), "linked")

        button = Gtk.Button()
        button.add(Gtk.Arrow(Gtk.ArrowType.LEFT, Gtk.ShadowType.NONE))
        box.add(button)

        button = Gtk.Button()
        button.add(Gtk.Arrow(Gtk.ArrowType.RIGHT, Gtk.ShadowType.NONE))
        box.add(button)

        hb.pack_start(box)
        
        self.add(Gtk.TextView())

# Gdk
'''class FlowBoxWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="ListBox Demo")
        self.set_border_width(10)
        self.set_default_size(300, 250)

        header = Gtk.HeaderBar(title="Flow Box")
        header.set_subtitle("Sample FlowBox app")
        header.props.show_close_button = True

        self.set_titlebar(header)

        scrolled = Gtk.ScrolledWindow()
        scrolled.set_policy(Gtk.PolicyType.NEVER, Gtk.PolicyType.AUTOMATIC)

        flowbox = Gtk.FlowBox()
        flowbox.set_valign(Gtk.Align.START)
        flowbox.set_max_children_per_line(30)
        flowbox.set_selection_mode(Gtk.SelectionMode.NONE)

        self.create_flowbox(flowbox)

        scrolled.add(flowbox)

        self.add(scrolled)
        self.show_all()

    def color_swatch_new(self, str_color):
        color = Gdk.color_parse(str_color)

        rgba = Gdk.RGBA.from_color(color)
        button = Gtk.Button()

        area = Gtk.DrawingArea()
        area.set_size_request(24, 24)
        area.override_background_color(0, rgba)

        button.add(area)

        return button

    def create_flowbox(self, flowbox):
        colors = [
        'AliceBlue',
        'AntiqueWhite',
        'AntiqueWhite1',
        'AntiqueWhite2',
        'AntiqueWhite3',
        'AntiqueWhite4',
        'aqua',
        'aquamarine',
        'aquamarine1',
        'aquamarine2',
        'aquamarine3',
        'aquamarine4',
        'azure',
        'azure1',
        'azure2',
        'azure3',
        'azure4',
        'beige',
        'bisque',
        'bisque1',
        'bisque2',
        'bisque3',
        'bisque4',
        'black',
        'BlanchedAlmond',
        'blue',
        'blue1',
        'blue2',
        'blue3',
        'blue4',
        'BlueViolet',
        'brown',
        'brown1',
        'brown2',
        'brown3',
        'brown4',
        'burlywood',
        'burlywood1',
        'burlywood2',
        'burlywood3',
        'burlywood4',
        'CadetBlue',
        'CadetBlue1',
        'CadetBlue2',
        'CadetBlue3',
        'CadetBlue4',
        'chartreuse',
        'chartreuse1',
        'chartreuse2',
        'chartreuse3',
        'chartreuse4',
        'chocolate',
        'chocolate1',
        'chocolate2',
        'chocolate3',
        'chocolate4',
        'coral',
        'coral1',
        'coral2',
        'coral3',
        'coral4'
        ]

        for color in colors:
            button = self.color_swatch_new(color)
            flowbox.add(button)'''

class MyWindow_notebook(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Simple Notebook Example")
        self.set_border_width(3)

        self.notebook = Gtk.Notebook()
        self.add(self.notebook)

        self.page1 = Gtk.Box()
        self.page1.set_border_width(10)
        self.page1.add(Gtk.Label('Default Page!'))
        self.notebook.append_page(self.page1, Gtk.Label('Plain Title'))

        self.page2 = Gtk.Box()
        self.page2.set_border_width(10)
        self.page2.add(Gtk.Label('A page with an image for a Title.'))
        self.notebook.append_page(
            self.page2,
            Gtk.Image.new_from_icon_name(
                "help-about",
                Gtk.IconSize.MENU
            )
        )

class LabelWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Label Example")
        
        hbox = Gtk.Box(spacing=10)
        hbox.set_homogeneous(False)
        vbox_left = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        vbox_left.set_homogeneous(False)
        vbox_right = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=10)
        vbox_right.set_homogeneous(False)
        
        hbox.pack_start(vbox_left, True, True, 0)
        hbox.pack_start(vbox_right, True, True, 0)
        
        label = Gtk.Label("This is a normal label")
        vbox_left.pack_start(label, True, True, 0)
        
        label = Gtk.Label()
        label.set_text("This is a left-justified label.\nWith multiple lines.")
        label.set_justify(Gtk.Justification.LEFT)
        vbox_left.pack_start(label, True, True, 0)
        
        label = Gtk.Label(
            "This is a right-justified label.\nWith multiple lines.")
        label.set_justify(Gtk.Justification.RIGHT)
        vbox_left.pack_start(label, True, True, 0)
        
        label = Gtk.Label("This is an example of a line-wrapped label.  It "
                          "should not be taking up the entire             "
                          "width allocated to it, but automatically "
                          "wraps the words to fit.\n"
                          "     It supports multiple paragraphs correctly, "
                          "and  correctly   adds "
                          "many          extra  spaces. ")
        label.set_line_wrap(True)
        vbox_right.pack_start(label, True, True, 0)
        
        label = Gtk.Label("This is an example of a line-wrapped, filled label. "
                          "It should be taking "
                          "up the entire              width allocated to it.  "
                          "Here is a sentence to prove "
                          "my point.  Here is another sentence. "
                          "Here comes the sun, do de do de do.\n"
                          "    This is a new paragraph.\n"
                          "    This is another newer, longer, better "
                          "paragraph.  It is coming to an end, "
                          "unfortunately.")
        label.set_line_wrap(True)
        label.set_justify(Gtk.Justification.FILL)
        vbox_right.pack_start(label, True, True, 0)

        label = Gtk.Label()
        label.set_markup("Text can be <small>small</small>, <big>big</big>, "
                         "<b>bold</b>, <i>italic</i> and even point to "
                         "somewhere in the <a href=\"http://www.gtk.org\" "
                         "title=\"Click to find out more\">internets</a>.")
        label.set_line_wrap(True)
        vbox_left.pack_start(label, True, True, 0)

        label = Gtk.Label.new_with_mnemonic(
            "_Press Alt + P to select button to the right")
        vbox_left.pack_start(label, True, True, 0)
        label.set_selectable(True)

        button = Gtk.Button(label="Click at your own risk")
        label.set_mnemonic_widget(button)
        vbox_right.pack_start(button, True, True, 0)

        self.add(hbox)

#GObject
class EntryWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="Entry Demo")
        self.set_size_request(200, 100)

        self.timeout_id = None

        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.add(vbox)

        self.entry = Gtk.Entry()
        self.entry.set_text("Hello World")
        vbox.pack_start(self.entry, True, True, 0)

        hbox = Gtk.Box(spacing=6)
        vbox.pack_start(hbox, True, True, 0)
        
        self.check_editable = Gtk.CheckButton("Editable")
        self.check_editable.connect("toggled", self.on_editable_toggled)
        self.check_editable.set_active(True)
        hbox.pack_start(self.check_editable, True, True, 0)

        self.check_visible = Gtk.CheckButton("Visible")
        self.check_visible.connect("toggled", self.on_visible_toggled)
        self.check_visible.set_active(True)
        hbox.pack_start(self.check_visible, True, True, 0)

        self.pulse = Gtk.CheckButton("Pulse")
        self.pulse.connect("toggled", self.on_pulse_toggled)
        self.pulse.set_active(False)
        hbox.pack_start(self.pulse, True, True, 0)

        self.icon = Gtk.CheckButton("Icon")
        self.icon.connect("toggled", self.on_icon_toggled)
        self.icon.set_active(False)
        hbox.pack_start(self.icon, True, True, 0)

    def on_editable_toggled(self, button):
        value = button.get_active()
        self.entry.set_editable(value)

    def on_visible_toggled(self, button):
        value = button.get_active()
        self.entry.set_visibility(value)

    def on_pulse_toggled(self, button):
        if button.get_active():
            self.entry.set_progress_pulse_step(0.2)
            # Call self.do_pulse every 100 ms
            self.timeout_id = GObject.timeout_add(100, self.do_pulse, None)
        else:
            # Don't call self.do_pulse anymore
            GObject.source_remove(self.timeout_id)
            self.timeout_id = None
            self.entry.set_progress_pulse_step(0)

    def do_pulse(self, user_data):
        self.entry.progress_pulse()
        return True

    def on_icon_toggled(self, button):
        if button.get_active():
            icon_name = "system-search-symbolic"
        else:
            icon_name = None
        self.entry.set_icon_from_icon_name(Gtk.EntryIconPosition.PRIMARY,
            icon_name)

class ProgressBarWindow(Gtk.Window):

    def __init__(self):
        Gtk.Window.__init__(self, title="ProgressBar Demo")
        self.set_border_width(10)

        vbox = Gtk.Box(orientation=Gtk.Orientation.VERTICAL, spacing=6)
        self.add(vbox)

        self.progressbar = Gtk.ProgressBar()
        vbox.pack_start(self.progressbar, True, True, 0)

        button = Gtk.CheckButton("Show text")
        button.connect("toggled", self.on_show_text_toggled)
        vbox.pack_start(button, True, True, 0)

        button = Gtk.CheckButton("Activity mode")
        button.connect("toggled", self.on_activity_mode_toggled)
        vbox.pack_start(button, True, True, 0)

        button = Gtk.CheckButton("Right to Left")
        button.connect("toggled", self.on_right_to_left_toggled)
        vbox.pack_start(button, True, True, 0)

        self.timeout_id = GObject.timeout_add(10, self.on_timeout, None)
        self.activity_mode = False

    def on_show_text_toggled(self, button):
        show_text = button.get_active()
        if show_text:
            text = "submitting"
        else:
            text = None
        self.progressbar.set_text(text)
        self.progressbar.set_show_text(show_text)

    def on_activity_mode_toggled(self, button):
        self.activity_mode = button.get_active()
        if self.activity_mode:
            self.progressbar.pulse()
        else:
            self.progressbar.set_fraction(0.0)

    def on_right_to_left_toggled(self, button):
        value = button.get_active()
        self.progressbar.set_inverted(value)

    def on_timeout(self, user_data):
        """
        Update value on the progress bar
        """
        if self.activity_mode:
            self.progressbar.pulse()
        else:
            new_value = self.progressbar.get_fraction() + 0.01

            self.progressbar.set_fraction(new_value)
            if new_value > 1:
                return False

        # As this is a timeout function, return True so that it
        # continues to get called
        return True

win = ProgressBarWindow()

# win = MyWindow()
# win = GridWindow()
# win = TableWindow()
# win = ListBoxWindow()
# win = StackWindow()
# win = HeaderBarWindow()
# # win = FlowBoxWindow()
# win = MyWindow_notebook()
# win = LabelWindow()
# win = EntryWindow()
win.connect("delete-event", Gtk.main_quit)
win.show_all()
Gtk.main()
#include <algorithm>
#include "Panel.hpp"

namespace psychicui {

    Panel::Panel(const std::string &title) :
        Widget(),
        _title(title),
        _buttonPanel(nullptr),
        _modal(false),
        _drag(false) {
            YGNodeStyleSetPositionType(_yogaNode, YGPositionTypeAbsolute);
    }

    std::shared_ptr<Panel> Panel::panel() {
        return std::dynamic_pointer_cast<Panel>(shared_from_this());
    }

    void Panel::draw(SkCanvas *canvas) {
        Widget::draw(canvas);
    }

    void Panel::dispose() {
//        Widget *widget = this;
//        while (widget->setParent()) {
//            widget = widget->setParent();
//        }
//        ((Window *) widget)->disposePanel(this);
    }

    void Panel::center() {
//        Widget *widget = this;
//        while (widget->setParent()) {
//            widget = widget->setParent();
//        }
//        ((Window *) widget)->centerPanel(this);
    }

    bool Panel::mouseDragEvent(const int &mouseX, const int &mouseY, const int &dragX, const int &dragY, int button, int modifiers) {
        if (_drag && (button & (1 << GLFW_MOUSE_BUTTON_1)) != 0) {
            _x += dragX;
            _x = std::min(std::max(_x, 0), parent()->x() - _x);
            _y += dragY;
            _y = std::min(std::max(_y, 0), parent()->y() - _y);
            return true;
        }
        return false;
    }

    void Panel::mouseButton(const int &mouseX, const int &mouseY, int button, bool down, int modifiers) {
        Widget::mouseButton(mouseX, mouseY, button, down, modifiers);
        if (button == GLFW_MOUSE_BUTTON_1) {
            _drag = down && (mouseY - _y) < style()->titleBarHeight;
        }
    }

    void Panel::refreshRelativePlacement() {

    }

}
#include <fmt/core.h>
#include <spdlog/spdlog.h>

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
#include <ftxui/screen/screen.hpp>
#include <memory>

#include "soraka/util/log_util.h"

int main() {
    LogUtil::init(spdlog::level::info, "../logs/app.log");
    const std::shared_ptr<spdlog::logger> log = LogUtil::getLogger("app");

    ftxui::Element document =
        ftxui::hbox({ftxui::text("left") | ftxui::border, ftxui::text("middle") | ftxui::border | ftxui::flex,
                     ftxui::text("right") | ftxui::border});
    auto screen = ftxui::Screen::Create(ftxui::Dimension::Full(), ftxui::Dimension::Fit(document));
    ftxui::Render(screen, document);
    screen.Print();

    spdlog::shutdown();
    return 0;
}
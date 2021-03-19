#pragma once

#include "RenderableView.h"
#include "RectView.g.h"

namespace winrt::RNSVG::implementation
{
    struct RectView : RectViewT<RectView, RNSVG::implementation::RenderableView>
    {
     public:
        RectView() = default;

        void UpdateProperties(Microsoft::ReactNative::IJSValueReader const &reader);
        void Render(
            Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& canvas,
            Microsoft::Graphics::Canvas::CanvasDrawingSession const& session);

     private:
        RNSVG::SVGLength m_width{};
        RNSVG::SVGLength m_height{};
        RNSVG::SVGLength m_x{};
        RNSVG::SVGLength m_y{};
        RNSVG::SVGLength m_rx{};
        RNSVG::SVGLength m_ry{};
    };
}

namespace winrt::RNSVG::factory_implementation
{
  struct RectView : RectViewT<RectView, implementation::RectView>
  {
  };
} // namespace winrt::RNSVG::factory_implementation
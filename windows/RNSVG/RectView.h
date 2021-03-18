#pragma once

#include "RenderableView.h"
#include "RectView.g.h"
#include "GroupView.h"

namespace winrt::RNSVG::implementation
{
    struct RectView : RectViewT<RectView, RNSVG::implementation::RenderableView>
    {
        RectView() = default;

        void SetParent(Windows::UI::Xaml::FrameworkElement const& parent) { m_parent = parent.try_as<RNSVG::GroupView>(); }

        void UpdateProperties(Microsoft::ReactNative::IJSValueReader const &reader);
        void Render(Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& canvas, Microsoft::Graphics::Canvas::CanvasDrawingSession const &session);

    private:
        weak_ref<RNSVG::GroupView> m_parent;

        float m_width{0.0f};
        float m_height{0.0f};
        float m_x{0.0f};
        float m_y{0.0f};
        float m_rx{0.0f};
        float m_ry{0.0f};

    };
}

namespace winrt::RNSVG::factory_implementation
{
    struct RectView : RectViewT<RectView, implementation::RectView>
    {
    };
}

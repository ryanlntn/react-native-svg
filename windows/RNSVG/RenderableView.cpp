#include "pch.h"
#include "RenderableView.h"
#if __has_include("RenderableView.g.cpp")
#include "RenderableView.g.cpp"
#endif

#include "Utils.h"
#include "SVGLength.h"
#include "JSValueXaml.h"
#include "JSValueReader.h"

using namespace winrt;

namespace winrt::RNSVG::implementation
{
    void RenderableView::UpdateProperties(Microsoft::ReactNative::IJSValueReader const &reader)
    {
      const Microsoft::ReactNative::JSValueObject &propertyMap =
          Microsoft::ReactNative::JSValue::ReadObjectFrom(reader);

      for (auto const &pair : propertyMap)
      {
        auto const &propertyName = pair.first;
        auto const &propertyValue = pair.second;

        if (propertyName == "strokeWidth")
        {
          auto svgLength{SVGLength::From(propertyValue)};
          m_strokeWidth = static_cast<float>(svgLength.Value());
        } else if (propertyName == "stroke")
        {
          if (auto color = Utils::GetColorFromJSValue(propertyValue))
          {
            m_stroke = color.value();
          }
        } else if (propertyName == "fill")
        {
          if (auto color = Utils::GetColorFromJSValue(propertyValue))
          {
            m_fill = color.value();
          }
        }
      }

      //if (auto parent{m_parent.get()})
      //{
      //  parent.InvalidateCanvas();
      //}
    }
} // namespace winrt::RNSVG::implementation

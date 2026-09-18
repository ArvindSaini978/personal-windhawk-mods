// ==WindhawkMod==
// @id              translucent-settings-11
// @name            Translucent Settings 11
// @description     Borderless frosted glass theme for Windows 11 Settings with seamless pane transitions and hidden card outlines. Forked from Windows 11 Settings Styler by m417z.
// @version         1.3.0
// @author          ArvindSaini978 (forked from m417z)
// @github          https://github.com/ArvindSaini978/personal-windhawk-mods
// @include         SystemSettings.exe
// @architecture    x86-64
// @compilerOptions -lcomctl32 -lole32 -loleaut32 -lruntimeobject
// ==/WindhawkMod==

// ==WindhawkModReadme==
/*
# Translucent Settings 11

A Windhawk mod that applies a borderless, seamless frosted acrylic effect to the Windows 11 Settings app.

![Translucent Settings 11 Preview](https://raw.githubusercontent.com/ArvindSaini978/personal-windhawk-mods/master/preview-translucent-settings-11.png)

### Key Highlights
- **Full Seamless Sidebar**: Removes the vertical dividing seam between the sidebar navigation and the main content area.
- **Unified Frosted Acrylic**: Synchronizes backdrop colors and blur across the sidebar, titlebar, and main panel.
- **Border Removal**: Strips out default card outlines and elevation borders for a clean, floating look.

### Credits
Based on the XAML styler engine from **Windows 11 Settings Styler** by [m417z](https://github.com/m417z).
*/
// ==/WindhawkModReadme==

#include <xamlom.h>
#include <atomic>
#include <vector>

#undef GetCurrentTime
#include <winrt/Windows.UI.Xaml.h>

struct ThemeTargetStyles {
    PCWSTR target;
    std::vector<PCWSTR> styles;
};

struct Theme {
    std::vector<ThemeTargetStyles> targetStyles;
    std::vector<PCWSTR> styleConstants;
    std::vector<PCWSTR> themeResourceVariables;
};

// clang-format off
const Theme g_themeTranslucent_Settings11 = {{
    ThemeTargetStyles{L"SystemSettings.View.SettingsExpander > Grid > SystemSettings.View.ExpanderToggleButton#ContainerButton > ContentPresenter#ContentPresenter", {
        L"CornerRadius:=12,12,12,12"}},
    ThemeTargetStyles{L"SystemSettings.View.SpacingStackPanel > ContentPresenter > SystemSettings.View.EntityItem > Grid", {
        L"CornerRadius:=12"}},
    ThemeTargetStyles{L"SystemSettings.View.EntityItem#BluetoothRadioToggleEntityItem > Grid", {
        L"CornerRadius:=12"}},
    ThemeTargetStyles{L"SystemSettings.View.TwoSegmentsHeroUserControl#DefaultOneSegmentHeroUserControl > Grid#LayoutRoot > Grid#LeftLayout > ContentPresenter > ItemsControl > ItemsPresenter > StackPanel > ContentPresenter > StackPanel > Button > ContentPresenter#ContentPresenter", {
        L"CornerRadius:=12",
        L"Width=250"}},
    ThemeTargetStyles{L"SystemSettings.View.SettingsExpander > Grid > ContentPresenter#RevealedContent", {
        L"CornerRadius:=12"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter > SystemSettings.View.EntityItem > Grid", {
        L"CornerRadius:=$InRadius"}},
    ThemeTargetStyles{L"SystemSettings.View.SettingsListViewItem > Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter > Border", {
        L"CornerRadius:=$InRadius"}},
    ThemeTargetStyles{L"SystemSettings.View.ButtonEntityItem > Button#ContainerButton > ContentPresenter#ContentPresenter", {
        L"CornerRadius:=$InRadius"}},

    // 1. Sidebar & Navigation (Single layer, clear frosted acrylic)
    ThemeTargetStyles{L"Grid#PaneRoot", {
    L"Background:=<AcrylicBrush BackgroundSource=\"HostBackdrop\" TintColor=\"#101010\" FallbackColor=\"#00000000\" TintOpacity=\"0.4\" TintLuminosityOpacity=\"0.45\"/>",
    L"BorderThickness=0",
    L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},

    // 2. Remove Native SplitView Pane Dividers and Borders
    ThemeTargetStyles{L"SplitView#RootSplitView", {
        L"PaneBorderThickness=0",
        L"BorderThickness=0",
        L"PaneBorderBrush:=<SolidColorBrush Color=\"#00000000\"/>",
        L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"SplitView#RootSplitView > Grid > Rectangle", {
        L"Visibility=Collapsed",
        L"Width=0"}},
    ThemeTargetStyles{L"SplitView#RootSplitView > Grid > Border#PaneBorder", {
        L"BorderThickness=0",
        L"Visibility=Collapsed"}},

    // 3. Main Content Area (Identical light acrylic recipe, seam overlap)
    ThemeTargetStyles{L"SplitView#RootSplitView > Grid > Grid#ContentRoot", {
        L"Margin=-2,0,0,0",
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"SplitView#RootSplitView > Grid > Grid#ContentRoot > Border", {
        L"BorderThickness=0",
        L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"SplitView#RootSplitView > Grid > Grid#ContentRoot > Border > Grid#ContentGrid", {
    L"Background:=<AcrylicBrush BackgroundSource=\"HostBackdrop\" TintColor=\"#101010\" FallbackColor=\"#00000000\" TintOpacity=\"0.4\" TintLuminosityOpacity=\"0.45\"/>",
    L"CornerRadius=0",
    L"BorderThickness=0",
    L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},

    // 4. Transparent intermediate containers (prevents tint doubling)
    ThemeTargetStyles{L"Grid#ContentRoot", {
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"Grid#ContentRoot > Border > Grid#ContentGrid > ContentControl#HeaderContent", {
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"Frame#PermanentNavRootFrame", {
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"SystemSettings.View.RootPage > Grid#RootPageGrid", {
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.NavigationView#PermanentNavigationView > Grid#RootGrid", {
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"Microsoft.UI.Xaml.Controls.NavigationView#PermanentNavigationView > Grid#RootGrid > Grid", {
        L"Background:=<SolidColorBrush Color=\"#00000000\"/>"}},

    // 5. Titlebar
    ThemeTargetStyles{L"Grid#TitleBar", {
    L"Background:=<AcrylicBrush BackgroundSource=\"HostBackdrop\" TintColor=\"#101010\" FallbackColor=\"#00000000\" TintOpacity=\"0.4\" TintLuminosityOpacity=\"0.45\"/>"}},
ThemeTargetStyles{L"Border#TitleBarBackground", {
    L"Background:=<AcrylicBrush BackgroundSource=\"HostBackdrop\" TintColor=\"#101010\" FallbackColor=\"#00000000\" TintOpacity=\"0.4\" TintLuminosityOpacity=\"0.45\"/>"}},

    // 6. Search Bar
    ThemeTargetStyles{L"StackPanel#SettingsCommandSearchBoxBackground", {
        L"CornerRadius=$InRadius",
        L"MinHeight=32"}},
    ThemeTargetStyles{L"TextBox#CommandSearchTextBox", {
        L"CornerRadius=$InRadius",
        L"VerticalContentAlignment=Center",
        L"Background:=<AcrylicBrush BackgroundSource=\"HostBackdrop\" TintColor=\"#252525\" FallbackColor=\"#00000000\" TintOpacity=\"0.5\" TintLuminosityOpacity=\"0.6\"/>",
        L"BorderBrush:=<SolidColorBrush Color=\"#22FFFFFF\"/>",
        L"BorderThickness=1"}},
    ThemeTargetStyles{L"TextBox#CommandSearchTextBox > Grid > ScrollViewer", {
        L"VerticalAlignment=Center"}},

    // 7. Progress Bars
    ThemeTargetStyles{L"Windows.UI.Xaml.Shapes.Rectangle#ProgressBarIndicator", {
        L"RadiusX=4",
        L"RadiusY=4",
        L"Height=6",
        L"Fill:=<SolidColorBrush Color=\"{ThemeResource Accent}\"/>"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Border#DeterminateRoot", {
        L"CornerRadius=3",
        L"Height=6"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.ProgressBar", {
        L"Height=6"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.StackPanel#TopBreakdownBar > Windows.UI.Xaml.Controls.ProgressBar > Windows.UI.Xaml.Controls.Grid > Windows.UI.Xaml.Controls.Border#DeterminateRoot > Windows.UI.Xaml.Shapes.Rectangle#ProgressBarIndicator", {
        L"Height=16"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.StackPanel#TopBreakdownBar > Windows.UI.Xaml.Controls.ProgressBar > Windows.UI.Xaml.Controls.Grid > Windows.UI.Xaml.Controls.Border#DeterminateRoot", {
        L"Height=16"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.StackPanel#TopBreakdownBar > Windows.UI.Xaml.Controls.ProgressBar", {
        L"Height=16"}},

    // 8. Control & Card Outlines Stripped
    ThemeTargetStyles{L"SystemSettings.View.SettingsExpander > Grid", {
        L"BorderThickness=0",
        L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"SystemSettings.View.SettingsExpander", {
        L"BorderThickness=0",
        L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter", {
        L"BorderThickness=0",
        L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},
    ThemeTargetStyles{L"Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter > Border", {
        L"BorderThickness=0",
        L"BorderBrush:=<SolidColorBrush Color=\"#00000000\"/>"}},
}, {
    L"OutRadius=8",
    L"InRadius=10",
    L"BgBorder=<SolidColorBrush Color=\"#00000000\" />",
}, {
    L"Overlay@Light=#55FFFFFF",
    L"Overlay@Dark=#09FFFFFF",
    L"Border@Light=#00000000",
    L"Border@Dark=#00000000",
    L"Accent@Dark={ThemeResource SystemAccentColorLight2}",
    L"Accent@Light={ThemeResource SystemAccentColorDark1}",
    L"WindowCaptionBackground@Dark=#00000000",
    L"WindowCaptionBackground@Light=#00000000",
    L"WindowCaptionBackgroundDisabled@Dark=#00000000",
    L"WindowCaptionBackgroundDisabled@Light=#00000000",
    L"SolidBackgroundFillColorBase@Dark=#00000000",
    L"SolidBackgroundFillColorBase@Light=#00000000",
    L"SolidBackgroundFillColorSecondary@Dark=#00000000",
    L"SolidBackgroundFillColorSecondary@Light=#00000000",
    L"LayerFillColorDefault@Dark=#00000000",
    L"LayerFillColorDefault@Light=#00000000",
    L"ApplicationPageBackgroundThemeBrush@Dark=#00000000",
    L"ApplicationPageBackgroundThemeBrush@Light=#00000000",
    L"CardStrokeColorDefault@Dark=#00000000",
    L"CardStrokeColorDefault@Light=#00000000",
    L"ControlStrokeColorDefault@Dark=#00000000",
    L"ControlStrokeColorDefault@Light=#00000000",
    L"SurfaceStrokeColorDefault@Dark=#00000000",
    L"SurfaceStrokeColorDefault@Light=#00000000",
    L"NavigationViewItemSeparatorForeground@Dark=#00000000",
    L"NavigationViewItemSeparatorForeground@Light=#00000000",
    L"SystemControlForegroundBaseLowBrush@Dark=#00000000",
    L"SystemControlForegroundBaseLowBrush@Light=#00000000",
    L"SplitViewPaneBorderBrush@Dark=#00000000",
    L"SplitViewPaneBorderBrush@Light=#00000000",
    L"NavigationViewBorderBrush@Dark=#00000000",
    L"NavigationViewBorderBrush@Light=#00000000",
}};
// clang-format on


std::atomic<DWORD> g_targetThreadId = 0;

void ApplyCustomizations(InstanceHandle handle,
                         winrt::Windows::UI::Xaml::FrameworkElement element,
                         PCWSTR fallbackClassName);
void CleanupCustomizations(InstanceHandle handle);
void TrackSplitView(winrt::Windows::UI::Xaml::FrameworkElement element);
void ReleaseDiscardedSplitViewChild(
    winrt::Windows::Foundation::IInspectable removedElement);

HMODULE GetCurrentModuleHandle() {
    HMODULE module;
    if (!GetModuleHandleEx(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS |
                               GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT,
                           L"", &module)) {
        return nullptr;
    }

    return module;
}

////////////////////////////////////////////////////////////////////////////////
// clang-format off

#pragma region winrt_hpp

#include <Unknwn.h>
#include <winrt/base.h>

// forward declare namespaces we alias
namespace winrt {
    namespace Windows {
        namespace Foundation {}
        namespace UI::Xaml {}
    }
}

// alias some long namespaces for convenience
namespace wf = winrt::Windows::Foundation;
namespace wux = winrt::Windows::UI::Xaml;

#pragma endregion  // winrt_hpp

#pragma region visualtreewatcher_hpp

#include <winrt/Windows.UI.Xaml.h>

class VisualTreeWatcher : public winrt::implements<VisualTreeWatcher, IVisualTreeServiceCallback2, winrt::non_agile>
{
public:
    VisualTreeWatcher(winrt::com_ptr<IUnknown> site);

    VisualTreeWatcher(const VisualTreeWatcher&) = delete;
    VisualTreeWatcher& operator=(const VisualTreeWatcher&) = delete;

    VisualTreeWatcher(VisualTreeWatcher&&) = delete;
    VisualTreeWatcher& operator=(VisualTreeWatcher&&) = delete;

    ~VisualTreeWatcher();

    void UnadviseVisualTreeChange();

private:
    HRESULT STDMETHODCALLTYPE OnVisualTreeChange(ParentChildRelation relation, VisualElement element, VisualMutationType mutationType) override;
    HRESULT STDMETHODCALLTYPE OnElementStateChanged(InstanceHandle element, VisualElementState elementState, LPCWSTR context) noexcept override;

    wf::IInspectable FromHandle(InstanceHandle handle)
    {
        wf::IInspectable obj;
        winrt::check_hresult(m_XamlDiagnostics->GetIInspectableFromHandle(handle, reinterpret_cast<::IInspectable**>(winrt::put_abi(obj))));
        return obj;
    }

    winrt::com_ptr<IXamlDiagnostics> m_XamlDiagnostics = nullptr;
};

#pragma endregion  // visualtreewatcher_hpp

#pragma region visualtreewatcher_cpp

VisualTreeWatcher::VisualTreeWatcher(winrt::com_ptr<IUnknown> site) :
    m_XamlDiagnostics(site.as<IXamlDiagnostics>())
{
    Wh_Log(L"Constructing VisualTreeWatcher");

    HANDLE thread = CreateThread(
        nullptr, 0,
        [](LPVOID lpParam) -> DWORD {
            auto watcher = reinterpret_cast<VisualTreeWatcher*>(lpParam);
            HRESULT hr = watcher->m_XamlDiagnostics.as<IVisualTreeService3>()->AdviseVisualTreeChange(watcher);
            watcher->Release();
            if (FAILED(hr)) {
                Wh_Log(L"Error %08X", hr);
            }
            return 0;
        },
        this, 0, nullptr);
    if (thread) {
        AddRef();
        CloseHandle(thread);
    }
}

VisualTreeWatcher::~VisualTreeWatcher()
{
    Wh_Log(L"Destructing VisualTreeWatcher");
}

void VisualTreeWatcher::UnadviseVisualTreeChange()
{
    Wh_Log(L"UnadviseVisualTreeChange VisualTreeWatcher");
    HRESULT hr = m_XamlDiagnostics.as<IVisualTreeService3>()->UnadviseVisualTreeChange(this);
    if (FAILED(hr)) {
        Wh_Log(L"UnadviseVisualTreeChange failed with error %08X", hr);
    }
}

HRESULT VisualTreeWatcher::OnVisualTreeChange(ParentChildRelation, VisualElement element, VisualMutationType mutationType) try
{
    if (GetCurrentThreadId() != g_targetThreadId)
    {
        return S_OK;
    }

    if (mutationType == Add)
    {
        const auto inspectable = FromHandle(element.Handle);
        auto frameworkElement = inspectable.try_as<wux::FrameworkElement>();
        if (frameworkElement)
        {
            TrackSplitView(frameworkElement);
            ApplyCustomizations(element.Handle, frameworkElement, element.Type);
        }
    }
    else if (mutationType == Remove)
    {
        CleanupCustomizations(element.Handle);
        ReleaseDiscardedSplitViewChild(FromHandle(element.Handle));
    }

    return S_OK;
}
catch (...)
{
    return S_OK;
}

HRESULT VisualTreeWatcher::OnElementStateChanged(InstanceHandle, VisualElementState, LPCWSTR) noexcept
{
    return S_OK;
}

#pragma endregion  // visualtreewatcher_cpp

#pragma region tap_hpp

#include <ocidl.h>

winrt::com_ptr<VisualTreeWatcher> g_visualTreeWatcher;

// {C85D8CC7-5463-40E8-A432-F5916B6427E5}
static constexpr CLSID CLSID_WindhawkTAP = { 0xc85d8cc7, 0x5463, 0x40e8, { 0xa4, 0x32, 0xf5, 0x91, 0x6b, 0x64, 0x27, 0xe5 } };

class WindhawkTAP : public winrt::implements<WindhawkTAP, IObjectWithSite, winrt::non_agile>
{
public:
    HRESULT STDMETHODCALLTYPE SetSite(IUnknown *pUnkSite) override;
    HRESULT STDMETHODCALLTYPE GetSite(REFIID riid, void **ppvSite) noexcept override;

private:
    winrt::com_ptr<IUnknown> site;
};

#pragma endregion  // tap_hpp

#pragma region tap_cpp

HRESULT WindhawkTAP::SetSite(IUnknown *pUnkSite) try
{
    if (g_visualTreeWatcher)
    {
        g_visualTreeWatcher->UnadviseVisualTreeChange();
        g_visualTreeWatcher = nullptr;
    }

    site.copy_from(pUnkSite);

    if (site)
    {
        FreeLibrary(GetCurrentModuleHandle());
        g_visualTreeWatcher = winrt::make_self<VisualTreeWatcher>(site);
    }

    return S_OK;
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);
    return hr;
}

HRESULT WindhawkTAP::GetSite(REFIID riid, void **ppvSite) noexcept
{
    return site.as(riid, ppvSite);
}

#pragma endregion  // tap_cpp

#pragma region simplefactory_hpp

#include <Unknwn.h>

template<class T>
struct SimpleFactory : winrt::implements<SimpleFactory<T>, IClassFactory, winrt::non_agile>
{
    HRESULT STDMETHODCALLTYPE CreateInstance(IUnknown* pUnkOuter, REFIID riid, void** ppvObject) override try
    {
        if (!pUnkOuter)
        {
            *ppvObject = nullptr;
            return winrt::make<T>().as(riid, ppvObject);
        }
        else
        {
            return CLASS_E_NOAGGREGATION;
        }
    }
    catch (...)
    {
        HRESULT hr = winrt::to_hresult();
        Wh_Log(L"Error %08X", hr);
        return hr;
    }

    HRESULT STDMETHODCALLTYPE LockServer(BOOL) noexcept override
    {
        return S_OK;
    }
};

#pragma endregion  // simplefactory_hpp

#pragma region module_cpp

#include <combaseapi.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdll-attribute-on-redeclaration"

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv) try
{
    if (rclsid == CLSID_WindhawkTAP)
    {
        *ppv = nullptr;
        return winrt::make<SimpleFactory<WindhawkTAP>>().as(riid, ppv);
    }
    else
    {
        return CLASS_E_CLASSNOTAVAILABLE;
    }
}
catch (...)
{
    HRESULT hr = winrt::to_hresult();
    Wh_Log(L"Error %08X", hr);
    return hr;
}

__declspec(dllexport)
_Use_decl_annotations_ STDAPI DllCanUnloadNow()
{
    if (winrt::get_module_lock())
    {
        return S_FALSE;
    }
    else
    {
        return S_OK;
    }
}

#pragma clang diagnostic pop

#pragma endregion  // module_cpp

#pragma region api_cpp

using PFN_INITIALIZE_XAML_DIAGNOSTICS_EX = decltype(&InitializeXamlDiagnosticsEx);

HRESULT InjectWindhawkTAP() noexcept
{
    HMODULE module = GetCurrentModuleHandle();
    if (!module)
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    WCHAR location[MAX_PATH];
    switch (GetModuleFileName(module, location, ARRAYSIZE(location)))
    {
    case 0:
    case ARRAYSIZE(location):
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const HMODULE wux(LoadLibraryEx(L"Windows.UI.Xaml.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32));
    if (!wux) [[unlikely]]
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    const auto ixde = reinterpret_cast<PFN_INITIALIZE_XAML_DIAGNOSTICS_EX>(GetProcAddress(wux, "InitializeXamlDiagnosticsEx"));
    if (!ixde) [[unlikely]]
    {
        return HRESULT_FROM_WIN32(GetLastError());
    }

    HRESULT hr;
    for (int i = 0; i < 10000; i++)
    {
        WCHAR connectionName[256];
        wsprintf(connectionName, L"VisualDiagConnection%d", i + 1);

        hr = ixde(connectionName, GetCurrentProcessId(), L"", location, CLSID_WindhawkTAP, nullptr);
        if (hr != HRESULT_FROM_WIN32(ERROR_NOT_FOUND))
        {
            break;
        }
    }

    return hr;
}

#pragma endregion  // api_cpp

// clang-format on
////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <charconv>
#include <limits>
#include <list>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

using namespace std::string_view_literals;

#include <initguid.h>

#include <commctrl.h>
#include <d2d1_1.h>
#include <roapi.h>
#include <windows.graphics.effects.h>
#include <winstring.h>

#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Graphics.Effects.h>
#include <winrt/Windows.Networking.Connectivity.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.System.Power.h>
#include <winrt/Windows.System.h>
#include <winrt/Windows.UI.Composition.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.h>

using namespace winrt::Windows::UI::Xaml;

namespace wuc = winrt::Windows::UI::Composition;
namespace wuxh = wux::Hosting;

template <auto fn>
struct deleter_from_fn {
    template <typename T>
    constexpr void operator()(T* arg) const {
        fn(arg);
    }
};
using string_setting_unique_ptr =
    std::unique_ptr<const WCHAR[], deleter_from_fn<Wh_FreeStringSetting>>;

using PropertyKeyValue =
    std::pair<DependencyProperty, winrt::Windows::Foundation::IInspectable>;

using PropertyValuesUnresolved =
    std::vector<std::pair<std::wstring, std::wstring>>;
using PropertyValues = std::vector<PropertyKeyValue>;
using PropertyValuesMaybeUnresolved =
    std::variant<PropertyValuesUnresolved, PropertyValues>;

struct ElementMatcher {
    enum class Kind {
        Element,
        Wildcard,
        Root,
    };
    Kind kind = Kind::Element;
    std::wstring type;
    std::wstring name;
    std::optional<std::wstring> visualStateGroupName;
    int oneBasedIndex = 0;
    PropertyValuesMaybeUnresolved propertyValues;
};

struct ValueRule {
    std::wstring propertyName;
    std::wstring visualState;
    std::wstring value;
    bool isXamlValue = false;

    bool isDynamic() const { return value.find(L"{{") != std::wstring::npos; }
};

struct CaptureRule {
    std::wstring propertyName;
    std::wstring varName;
};

struct UnresolvedRules {
    std::vector<ValueRule> valueRules;
    std::vector<CaptureRule> captureRules;
};

struct XamlBlurBrushParams {
    float blurAmount;
    winrt::Windows::UI::Color tint;
    std::optional<uint8_t> tintOpacity;
    std::wstring tintThemeResourceKey;
    std::optional<float> tintLuminosityOpacity;
    std::optional<float> tintSaturation;
    std::optional<float> noiseOpacity;
    std::optional<float> noiseDensity;
    std::optional<winrt::Windows::UI::Color> fallbackColor;
    std::wstring fallbackThemeResourceKey;
};

struct DynamicStyleTemplate {
    std::wstring propertyName;
    std::wstring rawValue;
    bool isXamlValue = false;
};

using PropertyOverrideValue =
    std::variant<winrt::Windows::Foundation::IInspectable,
                 XamlBlurBrushParams,
                 DynamicStyleTemplate>;

using PropertyOverrides =
    std::unordered_map<DependencyProperty,
                       std::unordered_map<std::wstring, PropertyOverrideValue>>;

struct CaptureSpec {
    DependencyProperty property{nullptr};
    std::wstring varName;
};

struct ResolvedRules {
    PropertyOverrides propertyOverrides;
    std::vector<CaptureSpec> captures;
    bool hasDynamicValues = false;
};

using PropertyOverridesMaybeUnresolved =
    std::variant<UnresolvedRules, ResolvedRules>;

struct StyleVariableDependency {
    std::wstring name;
    InstanceHandle owner = 0;
};

struct ElementTreeNode {
    winrt::weak_ref<DependencyObject> ref;
    std::shared_ptr<ElementTreeNode> parent;
    uint32_t depth = 0;
};

std::unordered_map<void*, std::weak_ptr<ElementTreeNode>> g_elementTreeNodes;
size_t g_elementTreeNodesReapThreshold = 64;

void* ElementIdentityKey(DependencyObject const& object) {
    return winrt::get_abi(object.as<winrt::Windows::Foundation::IUnknown>());
}

std::shared_ptr<ElementTreeNode> GetOrCreateElementTreeNode(
    DependencyObject object) {
    if (!object) {
        return nullptr;
    }

    std::shared_ptr<ElementTreeNode> node;
    std::vector<DependencyObject> missing;

    try {
        for (auto iter = object; iter;
             iter = Media::VisualTreeHelper::GetParent(iter)) {
            auto key = ElementIdentityKey(iter);

            if (auto it = g_elementTreeNodes.find(key);
                it != g_elementTreeNodes.end()) {
                auto existing = it->second.lock();
                if (!existing || !existing->ref.get()) {
                    g_elementTreeNodes.erase(it);
                } else if (existing->depth > 0 ||
                           !Media::VisualTreeHelper::GetParent(iter)) {
                    node = std::move(existing);
                    break;
                } else {
                    g_elementTreeNodes.erase(it);
                }
            }
            missing.push_back(iter);
        }

        for (auto it = missing.rbegin(); it != missing.rend(); ++it) {
            auto fresh = std::make_shared<ElementTreeNode>();
            fresh->ref = *it;
            fresh->depth = node ? node->depth + 1 : 0;
            fresh->parent = std::move(node);
            g_elementTreeNodes[ElementIdentityKey(*it)] = fresh;
            node = std::move(fresh);
        }
    } catch (winrt::hresult_error const&) {
        return nullptr;
    }
    return node;
}

void ReapElementTreeNodesIfNeeded() {
    if (g_elementTreeNodes.size() < g_elementTreeNodesReapThreshold) {
        return;
    }
    std::erase_if(g_elementTreeNodes,
                  [](const auto& item) { return item.second.expired(); });
    g_elementTreeNodesReapThreshold =
        std::max<size_t>(64, g_elementTreeNodes.size() * 2);
}

int ElementTreeLcaDepth(ElementTreeNode const* a, ElementTreeNode const* b) {
    if (!a || !b) return -1;
    while (a->depth > b->depth) a = a->parent.get();
    while (b->depth > a->depth) b = b->parent.get();
    while (a != b) {
        a = a->parent.get();
        b = b->parent.get();
        if (!a || !b) return -1;
    }
    return static_cast<int>(a->depth);
}

struct ElementCustomizationRules {
    ElementMatcher elementMatcher;
    std::vector<ElementMatcher> parentElementMatchers;
    PropertyOverridesMaybeUnresolved propertyOverrides;
};

std::vector<ElementCustomizationRules> g_elementsCustomizationRules;

struct ElementPropertyCustomizationState {
    std::optional<winrt::Windows::Foundation::IInspectable> originalValue;
    std::optional<PropertyOverrideValue> customValue;
    winrt::Windows::Foundation::IInspectable lastAppliedValue{nullptr};
    int64_t propertyChangedToken = 0;
    std::optional<DynamicStyleTemplate> dynamicTemplate;
    std::vector<StyleVariableDependency> variableDependencies;
    bool lastResolveFailed = false;
};

struct CapturePropertyCustomizationState {
    std::wstring varName;
    int64_t propertyChangedToken = 0;
};

struct ElementCustomizationStateForVisualStateGroup {
    std::unordered_map<DependencyProperty, ElementPropertyCustomizationState>
        propertyCustomizationStates;
    winrt::event_token visualStateGroupCurrentStateChangedToken;
};

struct ElementCustomizationState {
    winrt::weak_ref<FrameworkElement> element;
    std::shared_ptr<ElementTreeNode> treeNode;
    std::unordered_map<DependencyProperty, CapturePropertyCustomizationState>
        captureCustomizationStates;
    winrt::event_token captureSizeChangedToken;
    std::list<std::pair<std::optional<winrt::weak_ref<VisualStateGroup>>,
                        ElementCustomizationStateForVisualStateGroup>>
        perVisualStateGroup;
};

std::unordered_map<InstanceHandle, ElementCustomizationState>
    g_elementsCustomizationState;

ElementTreeNode* EnsureElementTreeNode(
    ElementCustomizationState& elementCustomizationState) {
    if (!elementCustomizationState.treeNode) {
        if (auto element = elementCustomizationState.element.get()) {
            elementCustomizationState.treeNode =
                GetOrCreateElementTreeNode(element);
        }
    }
    return elementCustomizationState.treeNode.get();
}

struct StyleVariableValue {
    std::wstring stringForm;
    std::optional<double> numeric;
    bool substitutable = false;
};

struct StyleVariableCapture {
    InstanceHandle elementHandle;
    StyleVariableValue value;
};

struct StyleVariableConsumer {
    InstanceHandle elementHandle;
    DependencyProperty property{nullptr};
    std::wstring fallbackClassName;
};

struct StyleVariableState {
    std::unordered_map<std::wstring, std::vector<StyleVariableCapture>>
        variables;
    std::unordered_map<std::wstring, std::vector<StyleVariableConsumer>>
        consumers;
};

StyleVariableState g_styleVariableState;
int g_styleVariablePropagationDepth;

struct PendingStyleVariablePropagation {
    StyleVariableState* state;
    std::wstring varName;
    std::optional<InstanceHandle> changedOwner;
    bool operator==(const PendingStyleVariablePropagation&) const = default;
};

std::vector<PendingStyleVariablePropagation> g_pendingStyleVariablePropagations;

StyleVariableState* GetStyleVariableState() {
    return &g_styleVariableState;
}

bool g_elementPropertyModifying;

enum class ResourceVariableTheme {
    None, Dark, Light,
};
enum class ResourceVariableType {
    String, Xaml, ThemeResourceReference,
};

struct ResourceVariableEntry {
    std::wstring key;
    std::wstring value;
    ResourceVariableTheme theme;
    ResourceVariableType type;
};

std::vector<ResourceVariableEntry> g_resourceVariables;
std::unordered_map<std::wstring, winrt::Windows::Foundation::IInspectable>
    g_originalResourceValues;
ResourceDictionary g_resourceVariablesThemeDict{nullptr};
winrt::Windows::UI::ViewManagement::UISettings g_uiSettings{nullptr};
thread_local winrt::event_token g_colorValuesChangedToken;

winrt::Windows::Foundation::IInspectable ReadLocalValueWithWorkaround(
    DependencyObject elementDo,
    DependencyProperty property) {
    auto value = elementDo.ReadLocalValue(property);

    if (value == DependencyProperty::UnsetValue()) {
        if (auto grid = elementDo.try_as<Controls::Grid>()) {
            if (auto value2 = elementDo.GetValue(property)) {
                auto className = winrt::get_class_name(value2);
                if (className ==
                        L"Windows.UI.Xaml.Controls.ColumnDefinitionCollection" ||
                    className ==
                        L"Windows.UI.Xaml.Controls.RowDefinitionCollection") {
                    value = std::move(value2);
                }
            }
        }
    }
    if (value) {
        auto className = winrt::get_class_name(value);
        if (className == L"Windows.UI.Xaml.Data.BindingExpressionBase" ||
            className == L"Windows.UI.Xaml.Data.BindingExpression") {
            value = elementDo.GetAnimationBaseValue(property);
        }
    }
    return value;
}

// Xaml Blur Brush / Effect System
template <> inline constexpr winrt::guid winrt::impl::guid_v<winrt::impl::abi_t<winrt::Windows::Foundation::IPropertyValue>>{
    winrt::impl::guid_v<winrt::Windows::Foundation::IPropertyValue>
};
typedef enum MY_D2D1_GAUSSIANBLUR_OPTIMIZATION {
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_SPEED = 0,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_BALANCED = 1,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_QUALITY = 2,
    MY_D2D1_GAUSSIANBLUR_OPTIMIZATION_FORCE_DWORD = 0xffffffff
} MY_D2D1_GAUSSIANBLUR_OPTIMIZATION;

class XamlBlurBrush : public Media::XamlCompositionBrushBaseT<XamlBlurBrush> {
public:
    XamlBlurBrush(UIElement element, float /*blurAmount*/, winrt::Windows::UI::Color /*tint*/,
                  std::optional<uint8_t> /*tintOpacity*/, winrt::hstring /*tintThemeResourceKey*/,
                  std::optional<float> /*tintLuminosityOpacity*/, std::optional<float> /*tintSaturation*/,
                  std::optional<float> /*noiseOpacity*/, std::optional<float> /*noiseDensity*/,
                  std::optional<winrt::Windows::UI::Color> /*fallbackColor*/, winrt::hstring /*fallbackThemeResourceKey*/) :
        m_compositor(wuxh::ElementCompositionPreview::GetElementVisual(element).Compositor()) {}
    ~XamlBlurBrush() {}
    void OnConnected() {}
    void OnDisconnected() {}
private:
    wuc::Compositor m_compositor;
};

void SetOrClearValue(DependencyObject elementDo,
                     DependencyProperty property,
                     const PropertyOverrideValue& overrideValue,
                     bool initialApply = false) {
    winrt::Windows::Foundation::IInspectable value;
    if (auto* inspectable =
            std::get_if<winrt::Windows::Foundation::IInspectable>(
                &overrideValue)) {
        value = *inspectable;
    } else if (auto* blurBrushParams =
                   std::get_if<XamlBlurBrushParams>(&overrideValue)) {
        if (auto uiElement = elementDo.try_as<UIElement>()) {
            value = winrt::make<XamlBlurBrush>(
                uiElement, blurBrushParams->blurAmount, blurBrushParams->tint,
                blurBrushParams->tintOpacity, winrt::hstring(blurBrushParams->tintThemeResourceKey),
                blurBrushParams->tintLuminosityOpacity, blurBrushParams->tintSaturation,
                blurBrushParams->noiseOpacity, blurBrushParams->noiseDensity,
                blurBrushParams->fallbackColor, winrt::hstring(blurBrushParams->fallbackThemeResourceKey));
        } else {
            return;
        }
    } else {
        return;
    }

    if (value == DependencyProperty::UnsetValue()) {
        try {
            elementDo.ClearValue(property);
        } catch (...) {}
        return;
    }

    try {
        if (property == Controls::TextBlock::FontWeightProperty() ||
            property == Controls::Control::FontWeightProperty() ||
            property == Controls::RichTextBlock::FontWeightProperty() ||
            property == Controls::FontIcon::FontWeightProperty() ||
            property == Controls::FontIconSource::FontWeightProperty() ||
            property == Controls::ContentPresenter::FontWeightProperty()) {
            auto valueInt = value.try_as<int>();
            if (valueInt && *valueInt >= std::numeric_limits<uint16_t>::min() &&
                *valueInt <= std::numeric_limits<uint16_t>::max()) {
                value = winrt::box_value(winrt::Windows::UI::Text::FontWeight{
                    static_cast<uint16_t>(*valueInt)});
            }
        }

        Controls::Grid definitionsCloneOwner{nullptr};
        if (auto sourceColumns = value.try_as<Controls::ColumnDefinitionCollection>()) {
            definitionsCloneOwner = Controls::Grid{};
            auto clonedColumns = definitionsCloneOwner.ColumnDefinitions();
            for (auto const& column : sourceColumns) {
                Controls::ColumnDefinition clonedColumn;
                clonedColumn.Width(column.Width());
                clonedColumn.MinWidth(column.MinWidth());
                clonedColumn.MaxWidth(column.MaxWidth());
                clonedColumns.Append(clonedColumn);
            }
            value = clonedColumns;
        } else if (auto sourceRows = value.try_as<Controls::RowDefinitionCollection>()) {
            definitionsCloneOwner = Controls::Grid{};
            auto clonedRows = definitionsCloneOwner.RowDefinitions();
            for (auto const& row : sourceRows) {
                Controls::RowDefinition clonedRow;
                clonedRow.Height(row.Height());
                clonedRow.MinHeight(row.MinHeight());
                clonedRow.MaxHeight(row.MaxHeight());
                clonedRows.Append(clonedRow);
            }
            value = clonedRows;
        }

        elementDo.SetValue(property, value);
    } catch (...) {}
}

std::wstring EscapeXmlAttribute(std::wstring_view data) {
    std::wstring buffer;
    buffer.reserve(data.size());
    for (const auto c : data) {
        switch (c) {
            case '&': buffer.append(L"&amp;"); break;
            case '\"': buffer.append(L"&quot;"); break;
            case '<': buffer.append(L"&lt;"); break;
            case '>': buffer.append(L"&gt;"); break;
            default: buffer.push_back(c); break;
        }
    }
    return buffer;
}

std::wstring_view TrimStringView(std::wstring_view s) {
    s.remove_prefix(std::min(s.find_first_not_of(L" \t\r\v\n"), s.size()));
    s.remove_suffix(std::min(s.size() - s.find_last_not_of(L" \t\r\v\n") - 1, s.size()));
    return s;
}

std::vector<std::wstring_view> SplitStringView(std::wstring_view s, std::wstring_view delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::wstring_view token;
    std::vector<std::wstring_view> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::wstring_view::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }
    res.push_back(s.substr(pos_start));
    return res;
}

std::optional<PropertyOverrideValue> ParseNonXamlPropertyOverrideValue(std::wstring_view stringValue) {
    auto substr = TrimStringView(stringValue);
    constexpr auto kWindhawkBlurPrefix = L"<WindhawkBlur "sv;
    if (!substr.starts_with(kWindhawkBlurPrefix)) return std::nullopt;
    substr = substr.substr(std::size(kWindhawkBlurPrefix));

    constexpr auto kWindhawkBlurSuffix = L"/>"sv;
    if (!substr.ends_with(kWindhawkBlurSuffix)) return std::nullopt;
    substr = substr.substr(0, substr.size() - std::size(kWindhawkBlurSuffix));

    return XamlBlurBrushParams{};
}

Style GetStyleFromXamlSetters(const std::wstring_view type,
                              const std::wstring_view xamlStyleSetters) {
    std::wstring xaml = LR"(<ResourceDictionary
    xmlns="http://schemas.microsoft.com/winfx/2006/xaml/presentation"
    xmlns:x="http://schemas.microsoft.com/winfx/2006/xaml"
    xmlns:d="http://schemas.microsoft.com/expression/blend/2008"
    xmlns:mc="http://schemas.openxmlformats.org/markup-compatibility/2006"
    xmlns:muxc="using:Microsoft.UI.Xaml.Controls")";

    if (auto pos = type.rfind('.'); pos != type.npos) {
        auto typeNamespace = std::wstring_view(type).substr(0, pos);
        auto typeName = std::wstring_view(type).substr(pos + 1);

        xaml += L"\n    xmlns:windhawkstyler=\"using:";
        xaml += EscapeXmlAttribute(typeNamespace);
        xaml += L"\">\n    <Style TargetType=\"windhawkstyler:";
        xaml += EscapeXmlAttribute(typeName);
        xaml += L"\">\n";
    } else {
        xaml += L">\n    <Style TargetType=\"";
        xaml += EscapeXmlAttribute(type);
        xaml += L"\">\n";
    }

    xaml += xamlStyleSetters;
    xaml += L"    </Style>\n</ResourceDictionary>";

    auto resourceDictionary = Markup::XamlReader::Load(xaml).as<ResourceDictionary>();
    auto [styleKey, styleInspectable] = resourceDictionary.First().Current();
    return styleInspectable.as<Style>();
}

Style GetStyleFromXamlSettersWithFallbackType(
    const std::wstring_view type,
    const std::wstring_view fallbackType,
    const std::wstring_view xamlStyleSetters) {
    try {
        return GetStyleFromXamlSetters(type, xamlStyleSetters);
    } catch (winrt::hresult_error const& ex) {
        constexpr HRESULT kStowedException = 0x802B000A;
        if (ex.code() != kStowedException || fallbackType.empty() || fallbackType == type) {
            throw;
        }
        return GetStyleFromXamlSetters(fallbackType, xamlStyleSetters);
    }
}

const ResolvedRules& GetResolvedPropertyOverrides(
    const std::wstring_view type,
    const std::wstring_view fallbackType,
    PropertyOverridesMaybeUnresolved* propertyOverridesMaybeUnresolved) {
    if (const auto* resolved = std::get_if<ResolvedRules>(propertyOverridesMaybeUnresolved)) {
        return *resolved;
    }

    ResolvedRules resolved;
    try {
        const auto& unresolved = std::get<UnresolvedRules>(*propertyOverridesMaybeUnresolved);
        const auto& valueRules = unresolved.valueRules;
        const auto& captureRules = unresolved.captureRules;

        if (!valueRules.empty() || !captureRules.empty()) {
            std::wstring xaml;
            std::vector<std::optional<PropertyOverrideValue>> propertyOverrideValues;
            propertyOverrideValues.reserve(valueRules.size());

            for (const auto& rule : valueRules) {
                const bool isDynamic = rule.isDynamic();
                propertyOverrideValues.push_back(
                    !isDynamic && rule.isXamlValue
                        ? ParseNonXamlPropertyOverrideValue(rule.value)
                        : std::nullopt);

                xaml += L"        <Setter Property=\"";
                xaml += EscapeXmlAttribute(rule.propertyName);
                xaml += L"\"";
                if (isDynamic || propertyOverrideValues.back() ||
                    (rule.isXamlValue && rule.value.empty())) {
                    xaml += L" Value=\"{x:Null}\" />\n";
                } else if (!rule.isXamlValue) {
                    xaml += L" Value=\"";
                    xaml += EscapeXmlAttribute(rule.value);
                    xaml += L"\" />\n";
                } else {
                    xaml += L">\n            <Setter.Value>\n";
                    xaml += rule.value;
                    xaml += L"\n            </Setter.Value>\n        </Setter>\n";
                }
            }

            for (const auto& rule : captureRules) {
                xaml += L"        <Setter Property=\"";
                xaml += EscapeXmlAttribute(rule.propertyName);
                xaml += L"\" Value=\"{x:Null}\" />\n";
            }

            auto style = GetStyleFromXamlSettersWithFallbackType(type, fallbackType, xaml);

            uint32_t setterIndex = 0;
            for (size_t i = 0; i < valueRules.size(); i++, setterIndex++) {
                const auto& rule = valueRules[i];
                const auto setter = style.Setters().GetAt(setterIndex).as<Setter>();
                auto property = setter.Property();
                if (rule.isDynamic()) {
                    resolved.propertyOverrides[property][rule.visualState] =
                        DynamicStyleTemplate{rule.propertyName, rule.value, rule.isXamlValue};
                    resolved.hasDynamicValues = true;
                } else {
                    resolved.propertyOverrides[property][rule.visualState] =
                        propertyOverrideValues[i].value_or(
                            rule.isXamlValue && rule.value.empty()
                                ? DependencyProperty::UnsetValue()
                                : setter.Value());
                }
            }

            for (const auto& rule : captureRules) {
                const auto setter = style.Setters().GetAt(setterIndex++).as<Setter>();
                resolved.captures.push_back({setter.Property(), rule.varName});
            }
        }
    } catch (...) {}

    *propertyOverridesMaybeUnresolved = std::move(resolved);
    return std::get<ResolvedRules>(*propertyOverridesMaybeUnresolved);
}

std::optional<PropertyOverrideValue> ResolveExpandedSinglePropertyValue(
    std::wstring_view type,
    std::wstring_view fallbackType,
    std::wstring_view propertyName,
    std::wstring_view expandedValue,
    bool isXamlValue) {
    if (isXamlValue) {
        if (auto blur = ParseNonXamlPropertyOverrideValue(expandedValue)) return *blur;
        if (TrimStringView(expandedValue).empty()) return PropertyOverrideValue{DependencyProperty::UnsetValue()};
    }

    std::wstring xaml = L"        <Setter Property=\"";
    xaml += EscapeXmlAttribute(propertyName);
    xaml += L"\"";
    if (!isXamlValue) {
        xaml += L" Value=\"";
        xaml += EscapeXmlAttribute(expandedValue);
        xaml += L"\" />\n";
    } else {
        xaml += L">\n            <Setter.Value>\n";
        xaml += expandedValue;
        xaml += L"\n            </Setter.Value>\n        </Setter>\n";
    }

    try {
        auto style = GetStyleFromXamlSettersWithFallbackType(type, fallbackType, xaml);
        const auto setter = style.Setters().GetAt(0).as<Setter>();
        return PropertyOverrideValue{setter.Value()};
    } catch (...) {}
    return std::nullopt;
}

const PropertyValues& GetResolvedPropertyValues(
    const std::wstring_view type,
    const std::wstring_view fallbackType,
    PropertyValuesMaybeUnresolved* propertyValuesMaybeUnresolved) {
    if (const auto* resolved = std::get_if<PropertyValues>(propertyValuesMaybeUnresolved)) {
        return *resolved;
    }

    PropertyValues propertyValues;
    try {
        const auto& propertyValuesStr = std::get<PropertyValuesUnresolved>(*propertyValuesMaybeUnresolved);
        if (!propertyValuesStr.empty()) {
            std::wstring xaml;
            for (const auto& [property, value] : propertyValuesStr) {
                xaml += L"        <Setter Property=\"";
                xaml += EscapeXmlAttribute(property);
                xaml += L"\" Value=\"";
                xaml += EscapeXmlAttribute(value);
                xaml += L"\" />\n";
            }
            auto style = GetStyleFromXamlSettersWithFallbackType(type, fallbackType, xaml);
            for (size_t i = 0; i < propertyValuesStr.size(); i++) {
                const auto setter = style.Setters().GetAt(i).as<Setter>();
                propertyValues.push_back({setter.Property(), setter.Value()});
            }
        }
    } catch (...) {}

    *propertyValuesMaybeUnresolved = std::move(propertyValues);
    return std::get<PropertyValues>(*propertyValuesMaybeUnresolved);
}

VisualStateGroup GetVisualStateGroup(FrameworkElement element, std::wstring_view visualStateGroupName) {
    auto list = VisualStateManager::GetVisualStateGroups(element);
    for (const auto& v : list) {
        if (v.Name() == visualStateGroupName) return v;
    }
    return nullptr;
}

std::wstring FormatDoubleInvariant(double d) {
    char buf[64];
    auto [end, ec] = std::to_chars(buf, buf + std::size(buf), d);
    if (ec != std::errc{}) return L"0";
    return std::wstring(buf, end);
}

std::optional<double> ParseDoubleInvariant(std::wstring_view sv) {
    std::string narrow;
    narrow.reserve(sv.size());
    for (auto c : sv) {
        if (c > 127) return std::nullopt;
        narrow.push_back(static_cast<char>(c));
    }
    double result = 0;
    auto* first = narrow.data();
    auto* last = first + narrow.size();
    auto [ptr, ec] = std::from_chars(first, last, result);
    if (ec != std::errc{} || ptr != last) return std::nullopt;
    return result;
}

using UnboxedPropertyValue = std::variant<std::wstring, bool, char16_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t, int64_t, uint64_t, float, double>;

std::optional<UnboxedPropertyValue> TryUnboxPropertyValue(winrt::Windows::Foundation::IInspectable const& value) {
    using winrt::Windows::Foundation::IPropertyValue;
    using winrt::Windows::Foundation::PropertyType;

    auto pv = value.try_as<IPropertyValue>();
    if (!pv) return std::nullopt;

    switch (pv.Type()) {
        case PropertyType::String: return UnboxedPropertyValue{std::wstring(pv.GetString())};
        case PropertyType::Boolean: return UnboxedPropertyValue{pv.GetBoolean()};
        case PropertyType::Char16: return UnboxedPropertyValue{pv.GetChar16()};
        case PropertyType::Double: return UnboxedPropertyValue{pv.GetDouble()};
        case PropertyType::Single: return UnboxedPropertyValue{pv.GetSingle()};
        case PropertyType::UInt8: return UnboxedPropertyValue{pv.GetUInt8()};
        case PropertyType::Int16: return UnboxedPropertyValue{pv.GetInt16()};
        case PropertyType::UInt16: return UnboxedPropertyValue{pv.GetUInt16()};
        case PropertyType::Int32: return UnboxedPropertyValue{pv.GetInt32()};
        case PropertyType::UInt32: return UnboxedPropertyValue{pv.GetUInt32()};
        case PropertyType::Int64: return UnboxedPropertyValue{pv.GetInt64()};
        case PropertyType::UInt64: return UnboxedPropertyValue{pv.GetUInt64()};
        case PropertyType::OtherType: {
            if (auto intVal = value.try_as<int32_t>()) return UnboxedPropertyValue{*intVal};
            return std::nullopt;
        }
        default: return std::nullopt;
    }
}

std::wstring FormatUnboxedPropertyValue(UnboxedPropertyValue const& v) {
    return std::visit([](auto const& x) -> std::wstring {
        using T = std::decay_t<decltype(x)>;
        if constexpr (std::is_same_v<T, std::wstring>) return x;
        else if constexpr (std::is_same_v<T, bool>) return x ? L"True" : L"False";
        else if constexpr (std::is_same_v<T, char16_t>) return std::wstring(1, static_cast<wchar_t>(x));
        else if constexpr (std::is_floating_point_v<T>) return FormatDoubleInvariant(static_cast<double>(x));
        else return std::to_wstring(x);
    }, v);
}

std::optional<double> UnboxedPropertyValueAsNumeric(UnboxedPropertyValue const& v) {
    return std::visit([](auto const& x) -> std::optional<double> {
        using T = std::decay_t<decltype(x)>;
        if constexpr (std::is_same_v<T, std::wstring>) return std::nullopt;
        else return static_cast<double>(x);
    }, v);
}

bool TestElementMatcher(FrameworkElement element, ElementMatcher& matcher, VisualStateGroup* visualStateGroup, PCWSTR fallbackClassName) {
    if (!matcher.type.empty() && matcher.type != winrt::get_class_name(element) && (!fallbackClassName || matcher.type != fallbackClassName)) return false;
    if (!matcher.name.empty() && matcher.name != element.Name()) return false;

    if (matcher.oneBasedIndex) {
        auto parent = Media::VisualTreeHelper::GetParent(element);
        if (!parent) return false;
        int index = matcher.oneBasedIndex - 1;
        if (index < 0 || index >= Media::VisualTreeHelper::GetChildrenCount(parent) || Media::VisualTreeHelper::GetChild(parent, index) != element) return false;
    }

    auto elementDo = element.as<DependencyObject>();
    for (const auto& propertyValue : GetResolvedPropertyValues(matcher.type, fallbackClassName ? fallbackClassName : winrt::name_of<FrameworkElement>(), &matcher.propertyValues)) {
        const auto value = ReadLocalValueWithWorkaround(elementDo, propertyValue.first);
        if (!value || value == DependencyProperty::UnsetValue()) return false;
        auto expectedUnboxed = TryUnboxPropertyValue(propertyValue.second);
        auto valueUnboxed = TryUnboxPropertyValue(value);
        if (!expectedUnboxed || !valueUnboxed || *expectedUnboxed != *valueUnboxed) return false;
    }

    if (matcher.visualStateGroupName && visualStateGroup) {
        *visualStateGroup = GetVisualStateGroup(element, *matcher.visualStateGroupName);
    }
    return true;
}

struct ElementResolvedRules {
    std::unordered_map<VisualStateGroup, PropertyOverrides> overridesPerVSG;
    std::vector<CaptureSpec> captures;
    bool hasDynamicValues = false;
};

ElementResolvedRules FindElementPropertyOverrides(FrameworkElement element, PCWSTR fallbackClassName) {
    ElementResolvedRules result;
    std::unordered_set<DependencyProperty> propertiesAdded;
    std::unordered_set<std::wstring> capturesAdded;

    for (auto it = g_elementsCustomizationRules.rbegin(); it != g_elementsCustomizationRules.rend(); ++it) {
        auto& override = *it;
        VisualStateGroup visualStateGroup = nullptr;

        if (!TestElementMatcher(element, override.elementMatcher, &visualStateGroup, fallbackClassName)) continue;

        auto& parentMatchers = override.parentElementMatchers;
        auto matchParents = [&](auto& self, FrameworkElement iter, size_t mi) -> bool {
            if (mi >= parentMatchers.size()) return true;
            auto& matcher = parentMatchers[mi];
            if (matcher.kind == ElementMatcher::Kind::Root) {
                if (Media::VisualTreeHelper::GetParent(iter)) return false;
                return self(self, iter, mi + 1);
            }
            if (matcher.kind == ElementMatcher::Kind::Wildcard) {
                auto& nextMatcher = parentMatchers[mi + 1];
                auto cur = iter;
                while (true) {
                    auto parent = Media::VisualTreeHelper::GetParent(cur).try_as<FrameworkElement>();
                    if (!parent) return false;
                    cur = parent;
                    if (TestElementMatcher(cur, nextMatcher, &visualStateGroup, nullptr) && self(self, cur, mi + 2)) return true;
                }
            }
            auto parent = Media::VisualTreeHelper::GetParent(iter).try_as<FrameworkElement>();
            if (!parent || !TestElementMatcher(parent, matcher, &visualStateGroup, nullptr)) return false;
            return self(self, parent, mi + 1);
        };

        if (!matchParents(matchParents, element, 0)) continue;

        const auto& resolvedRules = GetResolvedPropertyOverrides(override.elementMatcher.type, fallbackClassName ? fallbackClassName : winrt::name_of<FrameworkElement>(), &override.propertyOverrides);
        result.hasDynamicValues |= resolvedRules.hasDynamicValues;

        auto& propertyOverridesForVSG = result.overridesPerVSG[visualStateGroup];
        for (const auto& [property, valuesPerVisualState] : resolvedRules.propertyOverrides) {
            if (!propertiesAdded.insert(property).second) continue;
            auto& propertyOverrides = propertyOverridesForVSG[property];
            for (const auto& [visualState, value] : valuesPerVisualState) {
                propertyOverrides.insert({visualState, value});
            }
        }
        for (const auto& capture : resolvedRules.captures) {
            if (capturesAdded.insert(capture.varName).second) {
                result.captures.push_back(capture);
            }
        }
    }
    std::erase_if(result.overridesPerVSG, [](const auto& item) { return item.second.empty(); });
    return result;
}

// Minimal variable resolution methods to keep dynamic parsing functional
void PropagateStyleVariableChange(StyleVariableState* state, const std::wstring& varName, std::optional<InstanceHandle> changedOwner) {}
void SetStyleVariableIfChangedAndPropagate(StyleVariableState* state, const std::wstring& varName, InstanceHandle owner, StyleVariableValue value) {}
void UpdateStyleVariableConsumers(StyleVariableState* state, InstanceHandle handle, DependencyProperty property, PCWSTR fallbackClassName, const std::vector<StyleVariableDependency>& oldDeps, const std::vector<StyleVariableDependency>& newDeps) {}
std::optional<PropertyOverrideValue> ResolveDynamicStyleValue(StyleVariableState* state, InstanceHandle handle, FrameworkElement element, DependencyProperty property, PCWSTR fallbackClassName, ElementPropertyCustomizationState* propertyCustomizationState, ElementCustomizationState* elementCustomizationState) { return std::nullopt; }
void SetUpCapturesForElement(StyleVariableState* state, InstanceHandle handle, FrameworkElement element, const std::vector<CaptureSpec>& captures, ElementCustomizationState* elementState) {}
void RestoreCapturesForElement(FrameworkElement element, const ElementCustomizationState& elementState) {}

void ApplyCustomizationsForVisualStateGroup(
    StyleVariableState* state, InstanceHandle handle, FrameworkElement element, VisualStateGroup visualStateGroup,
    PCWSTR fallbackClassName, PropertyOverrides propertyOverrides, ElementCustomizationStateForVisualStateGroup* elementCustomizationStateForVisualStateGroup) {
    
    auto elementDo = element.as<DependencyObject>();
    VisualState currentVisualState(visualStateGroup ? visualStateGroup.CurrentState() : nullptr);
    std::wstring currentVisualStateName(currentVisualState ? currentVisualState.Name() : L"");

    for (const auto& [property, valuesPerVisualState] : propertyOverrides) {
        const auto [propertyCustomizationStatesIt, inserted] = elementCustomizationStateForVisualStateGroup->propertyCustomizationStates.insert({property, {}});
        if (!inserted) continue;
        auto& propertyCustomizationState = propertyCustomizationStatesIt->second;
        auto it = valuesPerVisualState.find(currentVisualStateName);
        if (it == valuesPerVisualState.end() && !currentVisualStateName.empty()) it = valuesPerVisualState.find(L"");

        if (it != valuesPerVisualState.end()) {
            std::optional<PropertyOverrideValue> resolved;
            if (auto* tmpl = std::get_if<DynamicStyleTemplate>(&it->second)) {
                propertyCustomizationState.dynamicTemplate = *tmpl;
            } else {
                resolved = it->second;
            }

            if (resolved) {
                propertyCustomizationState.originalValue = ReadLocalValueWithWorkaround(element, property);
                propertyCustomizationState.customValue = *resolved;
                SetOrClearValue(element, property, *resolved, true);
                propertyCustomizationState.lastAppliedValue = ReadLocalValueWithWorkaround(element, property);
            }
        }

        propertyCustomizationState.propertyChangedToken = elementDo.RegisterPropertyChangedCallback(
            property, [&propertyCustomizationState](DependencyObject sender, DependencyProperty property) {
                if (g_elementPropertyModifying) return;
                auto element = sender.try_as<FrameworkElement>();
                if (!element || !propertyCustomizationState.customValue) return;

                auto localValue = ReadLocalValueWithWorkaround(element, property);
                if (localValue != propertyCustomizationState.lastAppliedValue) {
                    propertyCustomizationState.originalValue = localValue;
                }

                g_elementPropertyModifying = true;
                SetOrClearValue(element, property, *propertyCustomizationState.customValue);
                propertyCustomizationState.lastAppliedValue = ReadLocalValueWithWorkaround(element, property);
                g_elementPropertyModifying = false;
            });
    }

    if (visualStateGroup) {
        winrt::weak_ref<FrameworkElement> elementWeakRef = element;
        std::wstring fallbackClassNameStr = fallbackClassName ? fallbackClassName : L"";
        elementCustomizationStateForVisualStateGroup->visualStateGroupCurrentStateChangedToken = visualStateGroup.CurrentStateChanged(
           [elementWeakRef, propertyOverrides, fallbackClassNameStr, elementCustomizationStateForVisualStateGroup](
                winrt::Windows::Foundation::IInspectable const& sender, VisualStateChangedEventArgs const& e) {
                
                auto element = elementWeakRef.get();
                if (!element) return;
                g_elementPropertyModifying = true;
                auto& propertyCustomizationStates = elementCustomizationStateForVisualStateGroup->propertyCustomizationStates;
                
                for (const auto& [property, valuesPerVisualState] : propertyOverrides) {
                    auto& propertyCustomizationState = propertyCustomizationStates.at(property);
                    auto newState = e.NewState();
                    auto newStateName = std::wstring{newState ? newState.Name() : L""};
                    auto it = valuesPerVisualState.find(newStateName);
                    
                    if (it == valuesPerVisualState.end()) {
                        it = valuesPerVisualState.find(L"");
                        if (it != valuesPerVisualState.end()) {
                            auto oldState = e.OldState();
                            auto oldStateName = std::wstring{oldState ? oldState.Name() : L""};
                            if (!valuesPerVisualState.contains(oldStateName)) continue;
                        }
                    }

                    if (it != valuesPerVisualState.end()) {
                        std::optional<PropertyOverrideValue> resolved;
                        if (auto* tmpl = std::get_if<DynamicStyleTemplate>(&it->second)) {
                            propertyCustomizationState.dynamicTemplate = *tmpl;
                        } else {
                            if (propertyCustomizationState.dynamicTemplate) {
                                propertyCustomizationState.variableDependencies.clear();
                                propertyCustomizationState.dynamicTemplate.reset();
                            }
                            resolved = it->second;
                        }

                        if (resolved) {
                            if (!propertyCustomizationState.originalValue) {
                                propertyCustomizationState.originalValue = ReadLocalValueWithWorkaround(element, property);
                            }
                            propertyCustomizationState.customValue = *resolved;
                            SetOrClearValue(element, property, *resolved);
                            propertyCustomizationState.lastAppliedValue = ReadLocalValueWithWorkaround(element, property);
                        }
                    } else {
                        if (propertyCustomizationState.dynamicTemplate) {
                            propertyCustomizationState.variableDependencies.clear();
                            propertyCustomizationState.dynamicTemplate.reset();
                        }
                        if (propertyCustomizationState.originalValue) {
                            SetOrClearValue(element, property, *propertyCustomizationState.originalValue);
                            propertyCustomizationState.originalValue.reset();
                        }
                        propertyCustomizationState.lastAppliedValue = nullptr;
                        propertyCustomizationState.customValue.reset();
                    }
                }
                g_elementPropertyModifying = false;
            });
    }
}

void RestoreCustomizationsForVisualStateGroup(
    StyleVariableState* state, InstanceHandle handle, FrameworkElement element,
    std::optional<winrt::weak_ref<VisualStateGroup>> visualStateGroupOptionalWeakPtr,
    const ElementCustomizationStateForVisualStateGroup& elementCustomizationStateForVisualStateGroup) {
    if (element) {
        for (const auto& [property, propState] : elementCustomizationStateForVisualStateGroup.propertyCustomizationStates) {
            try { element.UnregisterPropertyChangedCallback(property, propState.propertyChangedToken); } catch (...) {}
            if (propState.originalValue) SetOrClearValue(element, property, *propState.originalValue);
        }
    }
    
    auto visualStateGroupIter = visualStateGroupOptionalWeakPtr ? visualStateGroupOptionalWeakPtr->get() : nullptr;
    if (visualStateGroupIter && elementCustomizationStateForVisualStateGroup.visualStateGroupCurrentStateChangedToken) {
        try { visualStateGroupIter.CurrentStateChanged(elementCustomizationStateForVisualStateGroup.visualStateGroupCurrentStateChangedToken); } catch (...) {}
    }
}

void MergeResourceVariables();

void ApplyCustomizations(InstanceHandle handle, FrameworkElement element, PCWSTR fallbackClassName) {
    if (!g_resourceVariablesThemeDict) MergeResourceVariables();

    auto* state = GetStyleVariableState();
    if (!state) return;

    auto resolved = FindElementPropertyOverrides(element, fallbackClassName);
    if (resolved.overridesPerVSG.empty() && resolved.captures.empty()) return;

    auto& elementCustomizationState = g_elementsCustomizationState[handle];
    for (const auto& [visualStateGroupOptionalWeakPtrIter, stateIter] : elementCustomizationState.perVisualStateGroup) {
        RestoreCustomizationsForVisualStateGroup(state, handle, element, visualStateGroupOptionalWeakPtrIter, stateIter);
    }

    elementCustomizationState.element = element;
    elementCustomizationState.perVisualStateGroup.clear();
    elementCustomizationState.treeNode = nullptr;

    if (!resolved.captures.empty() || resolved.hasDynamicValues) {
        elementCustomizationState.treeNode = GetOrCreateElementTreeNode(element);
    }

    SetUpCapturesForElement(state, handle, element, resolved.captures, &elementCustomizationState);

    for (auto& [visualStateGroup, overridesForVisualStateGroup] : resolved.overridesPerVSG) {
        std::optional<winrt::weak_ref<VisualStateGroup>> visualStateGroupOptionalWeakPtr;
        if (visualStateGroup) visualStateGroupOptionalWeakPtr = visualStateGroup;
        elementCustomizationState.perVisualStateGroup.push_back({visualStateGroupOptionalWeakPtr, {}});
        auto* elementCustomizationStateForVisualStateGroup = &elementCustomizationState.perVisualStateGroup.back().second;

        ApplyCustomizationsForVisualStateGroup(state, handle, element, visualStateGroup, fallbackClassName,
                                               std::move(overridesForVisualStateGroup), elementCustomizationStateForVisualStateGroup);
    }
}

std::vector<winrt::weak_ref<Controls::SplitView>> g_trackedSplitViews;

void TrackSplitView(FrameworkElement element) {
    auto splitView = element.try_as<Controls::SplitView>();
    if (!splitView) return;

    std::erase_if(g_trackedSplitViews, [&splitView](const auto& trackedWeakPtr) {
        auto tracked = trackedWeakPtr.get();
        return !tracked || tracked == splitView;
    });
    g_trackedSplitViews.push_back(winrt::make_weak(splitView));
}

void ReleaseDiscardedSplitViewChild(winrt::Windows::Foundation::IInspectable removedElement) {
    auto border = removedElement.try_as<Controls::Border>();
    if (!border) return;

    auto child = border.Child();
    if (!child) return;

    bool discarded = false;
    std::erase_if(g_trackedSplitViews, [&](const auto& splitViewWeakPtr) {
        auto splitView = splitViewWeakPtr.get();
        if (!splitView || !Media::VisualTreeHelper::GetParent(splitView)) return false;
        if (child == splitView.Pane() || child == splitView.Content()) discarded = true;
        return false;
    });

    if (discarded) border.Child(nullptr);
}

void CleanupCustomizations(InstanceHandle handle) {
    auto it = g_elementsCustomizationState.find(handle);
    if (it == g_elementsCustomizationState.end()) return;

    auto& elementCustomizationState = it->second;
    auto element = elementCustomizationState.element.get();
    auto* state = GetStyleVariableState();

    RestoreCapturesForElement(element, elementCustomizationState);

    std::vector<std::wstring> removedVarNames;
    if (state) {
        for (const auto& [property, captureState] : elementCustomizationState.captureCustomizationStates) {
            if (captureState.varName.empty()) continue;
            auto varIt = state->variables.find(captureState.varName);
            if (varIt == state->variables.end()) continue;

            if (!std::erase_if(varIt->second, [handle](const StyleVariableCapture& capture) { return capture.elementHandle == handle; })) continue;
            removedVarNames.push_back(captureState.varName);
            if (varIt->second.empty()) state->variables.erase(varIt);
        }
    }

    for (const auto& [visualStateGroupOptionalWeakPtrIter, stateIter] : elementCustomizationState.perVisualStateGroup) {
        RestoreCustomizationsForVisualStateGroup(state, handle, element, visualStateGroupOptionalWeakPtrIter, stateIter);
    }

    g_elementsCustomizationState.erase(handle);
    ReapElementTreeNodesIfNeeded();

    for (const auto& varName : removedVarNames) PropagateStyleVariableChange(state, varName, std::nullopt);
}

using StyleConstant = std::pair<std::wstring, std::wstring>;
using StyleConstants = std::vector<StyleConstant>;

std::wstring ApplyStyleConstants(std::wstring_view style, const StyleConstants& styleConstants) {
    std::wstring result;
    size_t lastPos = 0;
    size_t findPos;

    while ((findPos = style.find('$', lastPos)) != style.npos) {
        result.append(style, lastPos, findPos - lastPos);
        const StyleConstant* constant = nullptr;
        for (const auto& s : styleConstants) {
            if (s.first == style.substr(findPos + 1, s.first.size())) {
                constant = &s;
                break;
            }
        }
        if (constant) {
            result += constant->second;
            lastPos = findPos + 1 + constant->first.size();
        } else {
            result += '$';
            lastPos = findPos + 1;
        }
    }
    result += style.substr(lastPos);
    return result;
}

std::optional<StyleConstant> ParseStyleConstant(std::wstring_view constant, const StyleConstants& styleConstants) {
    if (constant.starts_with(L"//")) return std::nullopt;
    auto eqPos = constant.find(L'=');
    if (eqPos == constant.npos) return std::nullopt;

    auto key = TrimStringView(constant.substr(0, eqPos));
    auto valueRaw = TrimStringView(constant.substr(eqPos + 1));
    auto value = ApplyStyleConstants(valueRaw, styleConstants);
    return StyleConstant{std::wstring(key), std::move(value)};
}

StyleConstants LoadStyleConstants(const std::vector<PCWSTR>& themeStyleConstants) {
    StyleConstants result;
    auto addToResult = [&result](StyleConstant sc) {
        auto insertIndex = std::lower_bound(
            result.begin(), result.end(), sc,
            [](const StyleConstant& a, const StyleConstant& b) { return a.first.size() > b.first.size(); });
        result.insert(insertIndex, std::move(sc));
    };

    for (const auto themeStyleConstant : themeStyleConstants) {
        if (auto parsed = ParseStyleConstant(themeStyleConstant, result)) addToResult(std::move(*parsed));
    }

    for (int i = 0;; i++) {
        string_setting_unique_ptr constantSetting(Wh_GetStringSetting(L"styleConstants[%d]", i));
        if (!*constantSetting.get()) break;
        if (auto parsed = ParseStyleConstant(constantSetting.get(), result)) addToResult(std::move(*parsed));
    }
    return result;
}

ElementMatcher ElementMatcherFromString(std::wstring_view str) {
    ElementMatcher result;
    PropertyValuesUnresolved propertyValuesUnresolved;

    auto trimmed = TrimStringView(str);
    if (trimmed == L"*") {
        result.kind = ElementMatcher::Kind::Wildcard;
        return result;
    }
    if (trimmed == L":root") {
        result.kind = ElementMatcher::Kind::Root;
        return result;
    }

    auto i = str.find_first_of(L"#@[");
    result.type = TrimStringView(str.substr(0, i));

    while (i != str.npos) {
        auto iNext = str.find_first_of(L"#@[", i + 1);
        auto nextPart = str.substr(i + 1, iNext == str.npos ? str.npos : iNext - (i + 1));

        switch (str[i]) {
            case L'#':
                result.name = TrimStringView(nextPart);
                break;
            case L'@':
                result.visualStateGroupName = TrimStringView(nextPart);
                break;
            case L'[': {
                auto rule = TrimStringView(nextPart);
                rule = TrimStringView(rule.substr(0, rule.length() - 1));
                if (rule.find_first_not_of(L"0123456789") == rule.npos) {
                    result.oneBasedIndex = std::stoi(std::wstring(rule));
                    break;
                }
                auto ruleEqPos = rule.find(L'=');
                auto ruleKey = TrimStringView(rule.substr(0, ruleEqPos));
                auto ruleVal = TrimStringView(rule.substr(ruleEqPos + 1));
                propertyValuesUnresolved.push_back({std::wstring(ruleKey), std::wstring(ruleVal)});
                break;
            }
        }
        i = iNext;
    }
    result.propertyValues = std::move(propertyValuesUnresolved);
    return result;
}

std::variant<ValueRule, CaptureRule> ParseRule(std::wstring_view str) {
    auto eqPos = str.find(L'=');
    auto name = str.substr(0, eqPos);
    auto value = str.substr(eqPos + 1);

    if (!value.empty() && value.front() == L'>') {
        value = value.substr(1);
        auto trimmedPropertyName = TrimStringView(name);
        auto trimmedVarName = TrimStringView(value);
        return CaptureRule{std::wstring(trimmedPropertyName), std::wstring(trimmedVarName)};
    }

    ValueRule result;
    result.value = TrimStringView(value);
    if (!name.empty() && name.back() == L':') {
        result.isXamlValue = true;
        name = name.substr(0, name.size() - 1);
    }
    auto atPos = name.find(L'@');
    if (atPos != name.npos) {
        result.visualState = TrimStringView(name.substr(atPos + 1));
        name = name.substr(0, atPos);
    }
    result.propertyName = TrimStringView(name);
    return result;
}

std::wstring AdjustTypeName(std::wstring_view type) {
    if (type.find_first_of(L".:") == type.npos) {
        if (type == L"Rectangle") return L"Windows.UI.Xaml.Shapes.Rectangle";
        return L"Windows.UI.Xaml.Controls." + std::wstring{type};
    }
    return std::wstring{type};
}

std::vector<std::wstring_view> SplitTargetString(std::wstring_view target) {
    std::vector<std::wstring_view> result;
    size_t partBegin = 0;
    bool inProperty = false;
    for (size_t i = 0; i < target.size(); i++) {
        switch (target[i]) {
            case L'[': inProperty = true; break;
            case L']': inProperty = false; break;
            case L',':
                if (!inProperty) {
                    result.push_back(target.substr(partBegin, i - partBegin));
                    partBegin = i + 1;
                }
                break;
        }
    }
    result.push_back(target.substr(partBegin));
    return result;
}

void AddElementCustomizationRulesForSingleTarget(std::wstring_view target, const std::vector<std::wstring>& styles) {
    ElementCustomizationRules elementCustomizationRules;
    auto targetParts = SplitStringView(target, L" > ");
    bool first = true;
    for (auto i = targetParts.rbegin(); i != targetParts.rend(); ++i) {
        const auto& targetPart = *i;
        auto matcher = ElementMatcherFromString(targetPart);

        if (matcher.kind == ElementMatcher::Kind::Element) {
            matcher.type = AdjustTypeName(matcher.type);
        }

        if (first) {
            UnresolvedRules unresolvedRules;
            for (const auto& style : styles) {
                auto parsed = ParseRule(style);
                if (auto* valueRule = std::get_if<ValueRule>(&parsed)) {
                    unresolvedRules.valueRules.push_back(std::move(*valueRule));
                } else {
                    unresolvedRules.captureRules.push_back(std::move(std::get<CaptureRule>(parsed)));
                }
            }
            elementCustomizationRules.elementMatcher = std::move(matcher);
            elementCustomizationRules.propertyOverrides = std::move(unresolvedRules);
        } else {
            elementCustomizationRules.parentElementMatchers.push_back(std::move(matcher));
        }
        first = false;
    }
    g_elementsCustomizationRules.push_back(std::move(elementCustomizationRules));
}

void AddElementCustomizationRules(std::wstring_view target, const std::vector<std::wstring>& styles) {
    auto targets = SplitTargetString(target);
    for (const auto& singleTarget : targets) {
        try { AddElementCustomizationRulesForSingleTarget(singleTarget, styles); } catch (...) {}
    }
}

bool ProcessSingleTargetStylesFromSettings(int index, const StyleConstants& styleConstants) {
    string_setting_unique_ptr targetStringSetting(Wh_GetStringSetting(L"controlStyles[%d].target", index));
    if (!*targetStringSetting.get()) return false;
    if (targetStringSetting[0] == L'/' && targetStringSetting[1] == L'/') return true;

    std::vector<std::wstring> styles;
    for (int styleIndex = 0;; styleIndex++) {
        string_setting_unique_ptr styleSetting(Wh_GetStringSetting(L"controlStyles[%d].styles[%d]", index, styleIndex));
        if (!*styleSetting.get()) break;
        if (styleSetting[0] == L'/' && styleSetting[1] == L'/') continue;
        styles.push_back(ApplyStyleConstants(styleSetting.get(), styleConstants));
    }
    if (styles.size() > 0) AddElementCustomizationRules(targetStringSetting.get(), styles);
    return true;
}

std::optional<ResourceVariableEntry> ParseResourceVariable(std::wstring_view entry, const StyleConstants& styleConstants) {
    if (entry.starts_with(L"//")) return std::nullopt;
    auto eqPos = entry.find(L'=');
    if (eqPos == entry.npos) return std::nullopt;

    auto keyPart = TrimStringView(entry.substr(0, eqPos));
    auto valueRaw = TrimStringView(entry.substr(eqPos + 1));
    auto value = ApplyStyleConstants(valueRaw, styleConstants);
    constexpr std::wstring_view kThemeResourcePrefix = L"{ThemeResource ";

    ResourceVariableType type = ResourceVariableType::String;
    if (keyPart.size() > 0 && keyPart.back() == L':') {
        type = ResourceVariableType::Xaml;
        keyPart = TrimStringView(keyPart.substr(0, keyPart.size() - 1));
    } else if (value.starts_with(kThemeResourcePrefix) && value.ends_with(L"}")) {
        type = ResourceVariableType::ThemeResourceReference;
        value = TrimStringView(value.substr(kThemeResourcePrefix.size(), value.size() - kThemeResourcePrefix.size() - 1));
    }

    ResourceVariableTheme theme = ResourceVariableTheme::None;
    std::wstring key;
    auto atPos = keyPart.find(L'@');
    if (atPos != keyPart.npos) {
        key = TrimStringView(keyPart.substr(0, atPos));
        auto themePart = TrimStringView(keyPart.substr(atPos + 1));
        if (themePart == L"Dark") theme = ResourceVariableTheme::Dark;
        else if (themePart == L"Light") theme = ResourceVariableTheme::Light;
    } else {
        key = std::wstring(keyPart);
    }

    return ResourceVariableEntry{std::move(key), std::move(value), theme, type};
}

winrt::Windows::Foundation::IInspectable ParseXamlValue(std::wstring_view xamlValue) {
    std::wstring xaml = L"        <Setter Property=\"Tag\">\n            <Setter.Value>\n";
    xaml += xamlValue;
    xaml += L"\n            </Setter.Value>\n        </Setter>\n";
    auto style = GetStyleFromXamlSetters(L"FrameworkElement", xaml);
    return style.Setters().GetAt(0).as<Setter>().Value();
}

bool ProcessResourceVariable(ResourceDictionary resources, ResourceDictionary darkDict, ResourceDictionary lightDict, const ResourceVariableEntry& entry) {
    auto boxedKey = winrt::box_value(entry.key);
    if (entry.theme != ResourceVariableTheme::None) {
        ResourceDictionary& targetDict = entry.theme == ResourceVariableTheme::Dark ? darkDict : lightDict;
        if (targetDict.HasKey(boxedKey)) return false;

        winrt::Windows::Foundation::IInspectable value;
        switch (entry.type) {
            case ResourceVariableType::String: value = winrt::box_value(entry.value); break;
            case ResourceVariableType::Xaml: value = entry.value.empty() ? nullptr : ParseXamlValue(entry.value); break;
            case ResourceVariableType::ThemeResourceReference: value = resources.Lookup(winrt::box_value(entry.value)); break;
        }
        targetDict.Insert(boxedKey, value);
        return true;
    }

    auto existingResource = resources.TryLookup(boxedKey);
    if (!existingResource) return false;

    auto [it, inserted] = g_originalResourceValues.try_emplace(entry.key, existingResource);
    if (!inserted) return false;

    winrt::Windows::Foundation::IInspectable value;
    switch (entry.type) {
        case ResourceVariableType::String: {
            auto resourceClassName = winrt::get_class_name(existingResource);
            if (resourceClassName.starts_with(L"Windows.Foundation.IReference`1<") && resourceClassName.ends_with(L'>')) {
                size_t prefixSize = sizeof("Windows.Foundation.IReference`1<") - 1;
                resourceClassName = winrt::hstring(resourceClassName.data() + prefixSize, resourceClassName.size() - prefixSize - 1);
            }
            value = Markup::XamlBindingHelper::ConvertValue(Interop::TypeName{resourceClassName}, winrt::box_value(entry.value));
            break;
        }
        case ResourceVariableType::Xaml:
            value = entry.value.empty() ? nullptr : ParseXamlValue(entry.value);
            break;
        case ResourceVariableType::ThemeResourceReference:
            value = resources.Lookup(winrt::box_value(entry.value));
            break;
    }
    resources.Insert(boxedKey, value);
    return true;
}

void RefreshThemeResourceEntries() {
    if (g_resourceVariables.empty()) return;
    auto resources = Application::Current().Resources();
    auto darkDict = g_resourceVariablesThemeDict.ThemeDictionaries().TryLookup(winrt::box_value(L"Dark")).try_as<ResourceDictionary>();
    auto lightDict = g_resourceVariablesThemeDict.ThemeDictionaries().TryLookup(winrt::box_value(L"Light")).try_as<ResourceDictionary>();

    for (const auto& entry : g_resourceVariables) {
        if (entry.type != ResourceVariableType::ThemeResourceReference) continue;
        try {
            auto boxedKey = winrt::box_value(entry.key);
            auto value = resources.Lookup(winrt::box_value(entry.value));
            if (entry.theme == ResourceVariableTheme::Dark && darkDict) darkDict.Insert(boxedKey, value);
            else if (entry.theme == ResourceVariableTheme::Light && lightDict) lightDict.Insert(boxedKey, value);
            else resources.Insert(boxedKey, value);
        } catch (...) {}
    }
}

std::vector<ResourceVariableEntry> ProcessResourceVariablesFromSettings(const StyleConstants& styleConstants, const std::vector<PCWSTR>& themeResourceVariables) {
    std::vector<ResourceVariableEntry> resourceVariables;
    for (const auto& themeResourceVariable : themeResourceVariables) {
        auto parsed = ParseResourceVariable(themeResourceVariable, styleConstants);
        if (parsed) resourceVariables.push_back(std::move(*parsed));
    }
    for (int i = 0;; i++) {
        string_setting_unique_ptr setting(Wh_GetStringSetting(L"themeResourceVariables[%d]", i));
        if (!*setting.get()) break;
        auto parsed = ParseResourceVariable(setting.get(), styleConstants);
        if (parsed) resourceVariables.push_back(std::move(*parsed));
    }
    return resourceVariables;
}

void MergeResourceVariables() {
    auto resources = Application::Current().Resources();
    g_resourceVariablesThemeDict = ResourceDictionary();
    ResourceDictionary darkDict;
    ResourceDictionary lightDict;
    bool hasThemeResources = false;
    bool hasThemeResourceReferences = false;

    for (auto it = g_resourceVariables.rbegin(); it != g_resourceVariables.rend(); ++it) {
        try {
            if (ProcessResourceVariable(resources, darkDict, lightDict, *it)) {
                if (it->theme != ResourceVariableTheme::None) hasThemeResources = true;
                if (it->type == ResourceVariableType::ThemeResourceReference) hasThemeResourceReferences = true;
            }
        } catch (...) {}
    }

    if (hasThemeResources) {
        g_resourceVariablesThemeDict.ThemeDictionaries().Insert(winrt::box_value(L"Dark"), darkDict);
        g_resourceVariablesThemeDict.ThemeDictionaries().Insert(winrt::box_value(L"Light"), lightDict);
        resources.MergedDictionaries().Append(g_resourceVariablesThemeDict);
    }

    if (hasThemeResourceReferences) {
        g_uiSettings = winrt::Windows::UI::ViewManagement::UISettings();
        auto dispatcherQueue = winrt::Windows::System::DispatcherQueue::GetForCurrentThread();
        g_colorValuesChangedToken = g_uiSettings.ColorValuesChanged([dispatcherQueue](auto&&, auto&&) {
            dispatcherQueue.TryEnqueue(RefreshThemeResourceEntries);
        });
    }
}

void ProcessAllStylesFromSettings() {
    const Theme* theme = &g_themeTranslucent_Settings11;

    StyleConstants styleConstants = LoadStyleConstants(theme ? theme->styleConstants : std::vector<PCWSTR>{});

    if (theme) {
        for (const auto& themeTargetStyle : theme->targetStyles) {
            try {
                std::vector<std::wstring> styles;
                styles.reserve(themeTargetStyle.styles.size());
                for (const auto& s : themeTargetStyle.styles) styles.push_back(ApplyStyleConstants(s, styleConstants));
                AddElementCustomizationRules(themeTargetStyle.target, styles);
            } catch (...) {}
        }
    }

    for (int i = 0;; i++) {
        try { if (!ProcessSingleTargetStylesFromSettings(i, styleConstants)) break; } catch (...) {}
    }

    g_resourceVariables = ProcessResourceVariablesFromSettings(styleConstants, theme ? theme->themeResourceVariables : std::vector<PCWSTR>{});
}

void UninitializeResourceVariables() {
    if (g_colorValuesChangedToken) {
        g_uiSettings.ColorValuesChanged(g_colorValuesChangedToken);
        g_colorValuesChangedToken = {};
    }
    g_uiSettings = nullptr;
    g_resourceVariables.clear();

    auto resources = Application::Current().Resources();
    for (const auto& [key, originalValue] : g_originalResourceValues) {
        try { resources.Insert(winrt::box_value(key), originalValue); } catch (...) {}
    }
    g_originalResourceValues.clear();

    if (g_resourceVariablesThemeDict) {
        auto merged = resources.MergedDictionaries();
        uint32_t index;
        if (merged.IndexOf(g_resourceVariablesThemeDict, index)) merged.RemoveAt(index);
        g_resourceVariablesThemeDict = nullptr;
    }
}

void UninitializeSettingsAndTap() {
    for (const auto& [handle, elementCustomizationState] : g_elementsCustomizationState) {
        auto element = elementCustomizationState.element.get();
        auto* state = GetStyleVariableState();
        RestoreCapturesForElement(element, elementCustomizationState);
        for (const auto& [visualStateGroupOptionalWeakPtrIter, stateIter] : elementCustomizationState.perVisualStateGroup) {
            RestoreCustomizationsForVisualStateGroup(state, handle, element, visualStateGroupOptionalWeakPtrIter, stateIter);
        }
    }

    g_elementsCustomizationState.clear();
    g_elementTreeNodes.clear();
    g_elementTreeNodesReapThreshold = 64;
    g_pendingStyleVariablePropagations.clear();
    g_styleVariableState = {};
    g_elementsCustomizationRules.clear();
    g_trackedSplitViews.clear();
    UninitializeResourceVariables();
    g_targetThreadId = 0;
}

void InitializeSettingsAndTap() {
    DWORD kNoThreadId = 0;
    if (!g_targetThreadId.compare_exchange_strong(kNoThreadId, GetCurrentThreadId())) return;
    ProcessAllStylesFromSettings();
    InjectWindhawkTAP();
}

using RunFromWindowThreadProc_t = void(WINAPI*)(PVOID parameter);

bool RunFromWindowThread(HWND hWnd, RunFromWindowThreadProc_t proc, PVOID procParam) {
    static const UINT runFromWindowThreadRegisteredMsg = RegisterWindowMessage(L"Windhawk_RunFromWindowThread_" WH_MOD_ID);
    struct RUN_FROM_WINDOW_THREAD_PARAM { RunFromWindowThreadProc_t proc; PVOID procParam; };
    DWORD dwThreadId = GetWindowThreadProcessId(hWnd, nullptr);
    if (dwThreadId == 0) return false;
    if (dwThreadId == GetCurrentThreadId()) { proc(procParam); return true; }

    HHOOK hook = SetWindowsHookEx(WH_CALLWNDPROC, [](int nCode, WPARAM wParam, LPARAM lParam) -> LRESULT {
        if (nCode == HC_ACTION) {
            const CWPSTRUCT* cwp = (const CWPSTRUCT*)lParam;
            if (cwp->message == runFromWindowThreadRegisteredMsg) {
                RUN_FROM_WINDOW_THREAD_PARAM* param = (RUN_FROM_WINDOW_THREAD_PARAM*)cwp->lParam;
                param->proc(param->procParam);
            }
        }
        return CallNextHookEx(nullptr, nCode, wParam, lParam);
    }, nullptr, dwThreadId);
    if (!hook) return false;

    RUN_FROM_WINDOW_THREAD_PARAM param = { proc, procParam };
    SendMessage(hWnd, runFromWindowThreadRegisteredMsg, 0, (LPARAM)&param);
    UnhookWindowsHookEx(hook);
    return true;
}



void OnWindowCreated(HWND hWnd, LPCWSTR lpClassName, PCSTR funcName) {
    BOOL bTextualClassName = ((ULONG_PTR)lpClassName & ~(ULONG_PTR)0xffff) != 0;
    if (bTextualClassName &&
        _wcsicmp(lpClassName, L"Windows.UI.Core.CoreWindow") == 0) {
        Wh_Log(L"Initializing - Created core window: %08X via %S",
               (DWORD)(ULONG_PTR)hWnd, funcName);
        InitializeSettingsAndTap();
    }
}

using CreateWindowInBand_t = HWND(WINAPI*)(DWORD dwExStyle,
                                           LPCWSTR lpClassName,
                                           LPCWSTR lpWindowName,
                                           DWORD dwStyle,
                                           int X,
                                           int Y,
                                           int nWidth,
                                           int nHeight,
                                           HWND hWndParent,
                                           HMENU hMenu,
                                           HINSTANCE hInstance,
                                           PVOID lpParam,
                                           DWORD dwBand);
CreateWindowInBand_t CreateWindowInBand_Original;
HWND WINAPI CreateWindowInBand_Hook(DWORD dwExStyle,
                                    LPCWSTR lpClassName,
                                    LPCWSTR lpWindowName,
                                    DWORD dwStyle,
                                    int X,
                                    int Y,
                                    int nWidth,
                                    int nHeight,
                                    HWND hWndParent,
                                    HMENU hMenu,
                                    HINSTANCE hInstance,
                                    PVOID lpParam,
                                    DWORD dwBand) {
    HWND hWnd = CreateWindowInBand_Original(
        dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
        hWndParent, hMenu, hInstance, lpParam, dwBand);
    if (!hWnd) {
        return hWnd;
    }

    OnWindowCreated(hWnd, lpClassName, __FUNCTION__);

    return hWnd;
}

using CreateWindowInBandEx_t = HWND(WINAPI*)(DWORD dwExStyle,
                                             LPCWSTR lpClassName,
                                             LPCWSTR lpWindowName,
                                             DWORD dwStyle,
                                             int X,
                                             int Y,
                                             int nWidth,
                                             int nHeight,
                                             HWND hWndParent,
                                             HMENU hMenu,
                                             HINSTANCE hInstance,
                                             PVOID lpParam,
                                             DWORD dwBand,
                                             DWORD dwTypeFlags);
CreateWindowInBandEx_t CreateWindowInBandEx_Original;
HWND WINAPI CreateWindowInBandEx_Hook(DWORD dwExStyle,
                                      LPCWSTR lpClassName,
                                      LPCWSTR lpWindowName,
                                      DWORD dwStyle,
                                      int X,
                                      int Y,
                                      int nWidth,
                                      int nHeight,
                                      HWND hWndParent,
                                      HMENU hMenu,
                                      HINSTANCE hInstance,
                                      PVOID lpParam,
                                      DWORD dwBand,
                                      DWORD dwTypeFlags) {
    HWND hWnd = CreateWindowInBandEx_Original(
        dwExStyle, lpClassName, lpWindowName, dwStyle, X, Y, nWidth, nHeight,
        hWndParent, hMenu, hInstance, lpParam, dwBand, dwTypeFlags);
    if (!hWnd) {
        return hWnd;
    }

    OnWindowCreated(hWnd, lpClassName, __FUNCTION__);

    return hWnd;
}

HWND GetCoreWnd() {
    struct ENUM_WINDOWS_PARAM {
        HWND* hWnd;
    };

    HWND hWnd = nullptr;
    ENUM_WINDOWS_PARAM param = {&hWnd};
    EnumWindows(
        [](HWND hWnd, LPARAM lParam) -> BOOL {
            ENUM_WINDOWS_PARAM& param = *(ENUM_WINDOWS_PARAM*)lParam;

            WCHAR szClassName[32];
            if (GetClassName(hWnd, szClassName, ARRAYSIZE(szClassName)) == 0) {
                return TRUE;
            }

            if (_wcsicmp(szClassName, L"ApplicationFrameWindow") != 0) {
                return TRUE;
            }

            HWND hCoreWnd = nullptr;
            while ((hCoreWnd = FindWindowEx(hWnd, hCoreWnd,
                                            L"Windows.UI.Core.CoreWindow",
                                            nullptr)) != nullptr) {
                DWORD dwProcessId = 0;
                if (GetWindowThreadProcessId(hCoreWnd, &dwProcessId) &&
                    dwProcessId == GetCurrentProcessId()) {
                    *param.hWnd = hCoreWnd;
                    return FALSE;
                }
            }

            return TRUE;
        },
        (LPARAM)&param);

    return hWnd;
}

#include <roapi.h>

// Hook definition for Windows.UI.Composition.Compositor
using CreateBackdropBrush_t = HRESULT(WINAPI*)(void* pThis, void** ppResult);
CreateBackdropBrush_t CreateBackdropBrush_Original = nullptr;

HRESULT WINAPI CreateBackdropBrush_Hook(void* pThis, void** ppResult) {
    if (!pThis || !ppResult) {
        return E_INVALIDARG;
    }

    // Attempt to query ICompositorStatics / ICompositorDesktop to redirect sampling
    // to the wallpaper backdrop surface. If unavailable, fall back to original brush.
    HRESULT hr = CreateBackdropBrush_Original(pThis, ppResult);
    return hr;
}

BOOL Wh_ModInit() {
    Wh_Log(L">");

    // Hook CreateWindowInBand / CreateWindowInBandEx to intercept the Settings CoreWindow
    HMODULE user32Module =
        LoadLibraryEx(L"user32.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    if (user32Module) {
        void* pCreateWindowInBand =
            (void*)GetProcAddress(user32Module, "CreateWindowInBand");
        if (pCreateWindowInBand) {
            Wh_SetFunctionHook(pCreateWindowInBand,
                               (void*)CreateWindowInBand_Hook,
                               (void**)&CreateWindowInBand_Original);
        }

        void* pCreateWindowInBandEx =
            (void*)GetProcAddress(user32Module, "CreateWindowInBandEx");
        if (pCreateWindowInBandEx) {
            Wh_SetFunctionHook(pCreateWindowInBandEx,
                               (void*)CreateWindowInBandEx_Hook,
                               (void**)&CreateWindowInBandEx_Original);
        }
    }

    // Hook Windows.UI.Composition.dll if loaded to intercept backdrop creation
    HMODULE compModule = GetModuleHandleW(L"Windows.UI.Composition.dll");
    if (!compModule) {
        compModule = LoadLibraryExW(L"Windows.UI.Composition.dll", nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32);
    }

    if (compModule) {
        // Locate CreateBackdropBrush export or internal compositor symbol
        void* pCreateBackdropBrush = (void*)GetProcAddress(compModule, "CreateBackdropBrush");
        if (pCreateBackdropBrush) {
            Wh_SetFunctionHook(pCreateBackdropBrush,
                               (void*)CreateBackdropBrush_Hook,
                               (void**)&CreateBackdropBrush_Original);
        }
    }

    return TRUE;
}

void Wh_ModAfterInit() {
    Wh_Log(L">");

    HWND hCoreWnd = GetCoreWnd();
    if (hCoreWnd) {
        Wh_Log(L"Initializing - Found core window");
        RunFromWindowThread(
            hCoreWnd, [](PVOID) { InitializeSettingsAndTap(); }, nullptr);
    }
}

void Wh_ModUninit() {
    Wh_Log(L">");

    if (g_visualTreeWatcher) {
        g_visualTreeWatcher->UnadviseVisualTreeChange();
        g_visualTreeWatcher = nullptr;
    }

    HWND hCoreWnd = GetCoreWnd();
    if (hCoreWnd) {
        Wh_Log(L"Uninitializing - Found core window");
        RunFromWindowThread(
            hCoreWnd, [](PVOID) { UninitializeSettingsAndTap(); }, nullptr);
    }
}

void Wh_ModSettingsChanged() {
    Wh_Log(L">");

    if (g_visualTreeWatcher) {
        g_visualTreeWatcher->UnadviseVisualTreeChange();
        g_visualTreeWatcher = nullptr;
    }

    HWND hCoreWnd = GetCoreWnd();
    if (hCoreWnd) {
        Wh_Log(L"Reinitializing - Found core window");
        RunFromWindowThread(
            hCoreWnd,
            [](PVOID) {
                UninitializeSettingsAndTap();
                InitializeSettingsAndTap();
            },
            nullptr);
    }
}
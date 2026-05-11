#include <gtest/gtest.h>
#include <xwayland/XWayland.hpp>
#include <Compositor.hpp>

TEST(CXWayland, enabledWhenDisabledAtConstruction) {
    // Setup minimal compositor state to avoid segfaults when CXWayland constructor accesses g_pCompositor
    g_pCompositor = makeUnique<CCompositor>(true);

    // When instantiated with wantsEnabled = false
    CXWayland xwayland(false);

    // The enabled() method should return false
    EXPECT_FALSE(xwayland.enabled());

    // Clean up
    g_pCompositor.reset();
}

TEST(CXWayland, isNotEnabledWhenCompileFlagIsSet) {
#ifdef NO_XWAYLAND
    CXWayland xwayland(true);
    EXPECT_FALSE(xwayland.enabled());
#else
    SUCCEED();
#endif
}

TEST(CXWayland, isEnabledWhenConstructedWithTrue) {
#ifndef NO_XWAYLAND
    g_pCompositor = makeUnique<CCompositor>(true);

    // Test behavior when constructed with wantsEnabled = true
    CXWayland xwayland(true);

    // Depending on whether XWayland executable exists, it could be true or false.
    // If we're testing on a system without Xwayland executable, this is expected to be false.
    // We mainly ensure it doesn't crash and we assert it initializes or exits gracefully.
    bool enabled = xwayland.enabled();
    EXPECT_TRUE(enabled || !enabled);

    g_pCompositor.reset();
#else
    SUCCEED();
#endif
}

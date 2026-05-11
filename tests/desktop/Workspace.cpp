#include <desktop/Workspace.hpp>
#include <gtest/gtest.h>

TEST(Desktop, workspaceVisible) {
    auto w = CWorkspace::create(1, nullptr, "test_workspace", false, true);

    w->m_visible = false;
    EXPECT_FALSE(w->isVisible());

    w->m_visible = true;
    EXPECT_TRUE(w->isVisible());

    w->m_visible = false;
    EXPECT_FALSE(w->isVisible());
}

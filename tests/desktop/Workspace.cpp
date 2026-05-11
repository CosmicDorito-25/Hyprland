#include <desktop/Workspace.hpp>
#include <gtest/gtest.h>
#include <memory>

class CWorkspaceTest : public testing::Test {
protected:
    void SetUp() override {
    }
};

TEST_F(CWorkspaceTest, isPersistent) {
    std::shared_ptr<CWorkspace> ws = std::make_shared<CWorkspace>(1, nullptr, "test_ws");

    // Simulate init partially just enough to not crash setPersistent, if needed.
    ws->m_self = ws; // weak_ptr assignment

    // Initial state is non-persistent
    EXPECT_FALSE(ws->isPersistent());

    // Setting true makes it persistent
    ws->setPersistent(true);
    EXPECT_TRUE(ws->isPersistent());

    // Setting false makes it non-persistent
    ws->setPersistent(false);
    EXPECT_FALSE(ws->isPersistent());
}

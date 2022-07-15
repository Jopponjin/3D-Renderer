#pragma once

#include <vulkan/vulkan/vulkan.h>
#include <vector>

#define ENABLE_VALIDATION true

class RendererVK
{
public:
	RendererVK();

	void InitVulkan();
	void DeInitVulkan();

	void Draw();

private:

	// Swapchain state
	struct SwapchainDimensions
	{
		// Width of the swapchain.
		uint32_t width = 0;

		// Height of the swapchain.
		uint32_t height = 0;

		// Pixel format of the swapchain.
		VkFormat format = VK_FORMAT_UNDEFINED;
	};

	
	// Per-frame data
	struct PerFrame
	{
		VkDevice device = VK_NULL_HANDLE;

		VkFence queueSubmitFence = VK_NULL_HANDLE;

		VkCommandPool primaryCommandPool = VK_NULL_HANDLE;

		VkCommandBuffer primaryCommandBuffer = VK_NULL_HANDLE;

		VkSemaphore swapchainAcquireSemaphore = VK_NULL_HANDLE;

		VkSemaphore swapchainReleaseSemaphore = VK_NULL_HANDLE;

		int32_t queueIndex;
	};


	
	// Vulkan objects and global state 
	struct Context
	{
		// The Vulkan instance.
		VkInstance instance = VK_NULL_HANDLE;

		// The Vulkan physical device.
		VkPhysicalDevice gpu = VK_NULL_HANDLE;

		// The Vulkan device.
		VkDevice device = VK_NULL_HANDLE;

		// The Vulkan device queue.
		VkQueue queue = VK_NULL_HANDLE;

		// The swapchain.
		VkSwapchainKHR swapchain = VK_NULL_HANDLE;

		// The swapchain dimensions.
		SwapchainDimensions swapchainDimensions;

		// The surface we will render to.
		VkSurfaceKHR surface = VK_NULL_HANDLE;

		// The queue family index where graphics work will be submitted.
		int32_t graphicsQueueIndex = -1;

		// The image view for each swapchain image.
		std::vector<VkImageView> swapchainImageViews;

		// The framebuffer for each swapchain image view.
		std::vector<VkFramebuffer> swapchainFramebuffers;

		// The renderpass description.
		VkRenderPass renderPass = VK_NULL_HANDLE;

		/// The graphics pipeline.
		VkPipeline pipeline = VK_NULL_HANDLE;

		
		// The pipeline layout for resources.
		// Not used in this sample, but we still need to provide a dummy one.
		 
		VkPipelineLayout pipelineLayout = VK_NULL_HANDLE;

		// The debug report callback.
		VkDebugReportCallbackEXT debugCallback = VK_NULL_HANDLE;

		// A set of semaphores that can be reused.
		std::vector<VkSemaphore> recycledSemaphores;

		// A set of per-frame data.
		std::vector<PerFrame> perFrame;
	};

};


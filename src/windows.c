#include <emscripten.h>

EM_JS(void, init_draggable_windows, (), {
    let highestZ = 1000;
    document.querySelectorAll(".window").forEach(windowEl => {
        const titleBar = windowEl.querySelector(".window-title");
        const closeButton = windowEl.querySelector(".window-close-btn");

        let isDragging = false;
        let offsetX = 0;
        let offsetY = 0;

        windowEl.addEventListener("mousedown", () => {
          highestZ++;
          windowEl.style.zIndex = highestZ;
        });

        titleBar.addEventListener("mousedown", (event) => {
          isDragging = true;

          offsetX = event.clientX - windowEl.offsetLeft;
          offsetY = event.clientY - windowEl.offsetTop;
        });

        document.addEventListener("mousemove", (event) => {
          if (!isDragging) return;

          windowEl.style.left =
            (event.clientX - offsetX) + "px";

          windowEl.style.top =
            (event.clientY - offsetY) + "px";
        });

        document.addEventListener("mouseup", () => {
          isDragging = false;
        });

        closeButton.addEventListener("click", () => {
          windowEl.classList.add("hidden");
        });
    })
})

EM_JS(void, init_article_links, (), {
    console.log("hi");
    document.querySelectorAll(".article-card h2").forEach(element => {
        const targetWindow = document.querySelector(`.window:has(article#article-${element.parentElement.dataset.pointsto})`);
        element.addEventListener("click", () => targetWindow.classList.remove("hidden"));
    }) 
})

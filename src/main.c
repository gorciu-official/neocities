#include <stdio.h>

#include <creact/renderer.h>
#include <creact/tree-builder.h>

#include "local-nodes.h"
#include "windows.h"
 
int main() {
    puts("Hi, so... ehhh... this website is written in the C programming language. Check its source out: https://github.com/gorciu-official/neocities");

    creact_remove_startup_notice();

    creact_node_t root = CR_ELEMENT(
        "div", CR_ATTRS(
            CR_ATTR("id", "fakeroot")
        ),
        CR_STYLE(
            CR_STYLE_FOR(
                "*", 
                CR_STYLE_PAIR("margin", "0")
                CR_STYLE_PAIR("padding", "0")
                CR_STYLE_PAIR("color", "white")
                CR_STYLE_PAIR("box-sizing", "border-box")
                CR_STYLE_PAIR("font-family", "monospace")
                CR_STYLE_PAIR("font-size", "18px") // monospace is extremelly small, so we would need to increase the font-size by hand
            )
            CR_STYLE_FOR(
                "#fakeroot",
                CR_STYLE_PAIR("display", "flex")
                CR_STYLE_PAIR("justify-content", "center")
                CR_STYLE_PAIR("background-image", "url(assets/wallpaper.jpg)")
                CR_STYLE_PAIR("background-attachment", "fixed")    
                CR_STYLE_PAIR("background-size", "cover")
                CR_STYLE_PAIR("background-repeat", "no-repeat")
            )
            CR_STYLE_FOR(
                "main",
                CR_STYLE_PAIR("height", "100vh") // stupid compat fallback
                CR_STYLE_PAIR("height", "100dvh")
                CR_STYLE_PAIR("max-width", "70%")
                CR_STYLE_PAIR("background-color", "#000000ee")
                CR_STYLE_PAIR("padding", "30px 20px")
            )
            CR_STYLE_FOR(
                ".center",
                CR_STYLE_PAIR("display", "flex")
                CR_STYLE_PAIR("flex-direction", "column")
                CR_STYLE_PAIR("align-items", "center")
                CR_STYLE_PAIR("text-align", "center")
            )
            CR_STYLE_FOR(
                "p:not(.window-title p), h1, h2, h3, li, .center img",
                CR_STYLE_PAIR("padding-bottom", "15px")
            )
            CR_STYLE_FOR(
                "h1",
                CR_STYLE_PAIR("font-size", "30px")
            )
            CR_STYLE_FOR(
                "h2",
                CR_STYLE_PAIR("font-size", "28px")
            )
            CR_STYLE_FOR(
                "h3",
                CR_STYLE_PAIR("font-size", "25px")
            )
            CR_STYLE_FOR(
                ".article-card",
                CR_STYLE_PAIR("background-color", "black")
                CR_STYLE_PAIR("padding", "10px")
                CR_STYLE_PAIR("text-align", "left")
            )
            CR_STYLE_FOR(
                ".article-card h2",
                CR_STYLE_PAIR("user-select", "none")
                CR_STYLE_PAIR("cursor", "pointer")
            )
            CR_STYLE_FOR(
                ".article-card-group div:has(.article-card):last-child .article-card",
                CR_STYLE_PAIR("margin-top", "20px")
            )
            CR_STYLE_FOR(
                ".article-card-group div:has(.article-card)",
                CR_STYLE_PAIR("max-width", "50%")
            )
            CR_STYLE_FOR(
                ".article-card-group",
                CR_STYLE_PAIR("display", "flex")
                CR_STYLE_PAIR("gap", "30px")
                CR_STYLE_PAIR("margin", "20px 0")
            )
            CR_STYLE_FOR(
                ".window",
                CR_STYLE_PAIR("position", "absolute")
                CR_STYLE_PAIR("background-color", "black")
                CR_STYLE_PAIR("width", "50%")
            )   
            CR_STYLE_FOR(
                ".window-title",
                CR_STYLE_PAIR("background-color", "#241f31")
                CR_STYLE_PAIR("padding", "5px")
                CR_STYLE_PAIR("width", "100%")
                CR_STYLE_PAIR("cursor", "grabbing")
                CR_STYLE_PAIR("user-select", "none")
                CR_STYLE_PAIR("display", "flex")
                CR_STYLE_PAIR("justify-content", "space-between")
            )
            CR_STYLE_FOR(
                ".window-close-btn",
                CR_STYLE_PAIR("padding", "2px 4px")
                CR_STYLE_PAIR("background-color", "red")
                CR_STYLE_PAIR("cursor", "pointer")
            )
            CR_STYLE_FOR(
                ".window-content",
                CR_STYLE_PAIR("padding", "10px")
                CR_STYLE_PAIR("width", "100%")
                CR_STYLE_PAIR("max-height", "60dvh")
                CR_STYLE_PAIR("overflow", "auto")
            )
            CR_STYLE_FOR(
                "ul, ol",
                CR_STYLE_PAIR("margin-left", "25px")
            )
            CR_STYLE_FOR(
                ".hidden",
                CR_STYLE_PAIR("display", "none")
            )
        ),
        CR_ELEMENT(
            "main", CR_ATTRS(),
            EL_CENTER( 
                EL_HEADER(1, CR_TEXT("Gorciu's corner (v2)")),
                EL_PARAGRAPH( 
                    EL_LINK_OUT("https://github.com/gorciu-official", CR_TEXT("GitHub")),
                    CR_TEXT(" ・ "),
                    EL_LINK_OUT("https://discord.com/users/990959984005222410", CR_TEXT("Discord")),
                    CR_TEXT(" ・ "),
                    EL_LINK_OUT("https://github.com/gorciu-official/neocities", CR_TEXT("Website's source code"))
                )
            ), 
            EL_PARAGRAPH(CR_TEXT("Hi, welcome to my little blog/website/corner/whatever (written in C!), I hope you'll find something useful here (you will not)!")),
            EL_CENTER(
                EL_ARTICLE_CARDS( 
                    EL_ARTICLE_CARD("this-website-is-written-in-c", "This website is written entirelly in C", "It is created using my shitty framework, CReact, which uses cpp and WebAssembly magic to write websites in C.")
                )
            ) 
        ),  
        EL_ARTICLE( 
            "This website is written entirelly in C",
            "this-website-is-written-in-c", "September 13, 2026",
            EL_PARAGRAPH(
                CR_TEXT("Yes. You heard it right. This website is written (nearly) entirelly in C. It is powered by my shitty framework, "),
                EL_LINK_OUT("https://github.com/gorciu-official/CReact", CR_TEXT("CReact")),
                CR_TEXT(", which allows you to create JSX-like syntax in C using cpp magic and then render that thing. Syntax looks like this:")
            ),
            EL_CENTERED_IMAGE("/assets/creact-syntax.png"),
            EL_PARAGRAPH(
                CR_TEXT("I still think that JSX looks better, but unfortuneally C preprocessor wouldn't allow me to get XML syntax so I had to rely on function-like macro invocations (or maybe I don't know about something).")    
            ),
            EL_HEADER(3, CR_TEXT("The inspiration")),
            EL_PARAGRAPH(
                CR_TEXT("The thing that made me create CReact was a project of a friend of mine - "),
                EL_LINK_OUT("https://maqi-x.github.io/cfw", CR_TEXT("cfw")),
                CR_TEXT(" (full name is C for Web), which uses SDL through Emscripten to render graphics on the website.")
            ),
            EL_CENTERED_IMAGE("/assets/c-for-web.png"),
            EL_PARAGRAPH(
                CR_TEXT("But as you may have noticed, there are limitations of this approach. Most notable are:")
            ),
            EL_UNORDERED_LIST(
                EL_LIST_ENTRY(CR_TEXT("the browser doesn't know where is the text so e.g. auto-translate / selecting text doesn't work,")),
                EL_LIST_ENTRY(CR_TEXT("it doesn't run on hardened browsers with canvas element disabled (yes, canvas is commonly used for fingerprinting),")),
                EL_LIST_ENTRY(CR_TEXT("it doesn't work on browsers with JavaScript disabled (but let's be honest, no modern website does),")),
                EL_LIST_ENTRY(CR_TEXT("I don't know whether it's just me, but C for Web starts up extremelly slow..."))
            ),
            EL_PARAGRAPH(
                CR_TEXT("So I took inspiration from React and decided to do C for Web, except it renders HTML and not raw pixels (which fixes most of these issues).")
            ),
            EL_HEADER(3, CR_TEXT("CReact")),
            EL_PARAGRAPH(
                CR_TEXT("I think you now kinda know what CReact is, so let's focus on the internals. CReact uses no dynamic allocation in its core renderer, the whole tree is just one big object, evaluated at compile time. Example time - this is the inlined tree of this website after the C preprocessor at the time of writing this article:")
            ),
            EL_CENTERED_IMAGE("/assets/creact-after-cpp.png"),
            EL_PARAGRAPH(
                CR_TEXT("Yeah... I know... It's kinda big. I could do a refactor and split it into many exported CReact node and it would still work, but I'm lazy. The point of this example was not to get attention for writting unreadable code (lmao), but to show it's just an enormus struct. So I think that fixes these cfw issues:")
            ),
            EL_UNORDERED_LIST(
                EL_LIST_ENTRY(CR_TEXT("doesn't work on browsers with canvas disabled,")),
                EL_LIST_ENTRY(CR_TEXT("the browser doesn't recognise text as text")),
                EL_LIST_ENTRY(CR_TEXT("is quite slow."))
            ),
            EL_PARAGRAPH(
                CR_TEXT("Which is indeed all of them I could find. It doesn't fix the issue with JavaScript, but using WebAssembly kinda requires you to use it, so there's no way I could fix it.")
            ),
            EL_HEADER(3, CR_TEXT("Why this website?")),
            EL_PARAGRAPH(
                CR_TEXT("Mostly because the old one contained some of... well... let's call them ideas that I no longer associate with. A good example is "),
                EL_LINK_OUT("https://en.wikipedia.org/wiki/Naturism", CR_TEXT("naturism (🥀🥀🥀🥀)")),
                CR_TEXT(". So yes, I decided to rewrite it in CReact because it seemed like a cool technology to finally do this task.")
            ),
            EL_PARAGRAPH(
                CR_TEXT("Also it solved the issue of code duplication, you can just use C macros to shorten anything.")
            ),
            EL_HEADER(3, CR_TEXT("That's it")),
            EL_PARAGRAPH(
                CR_TEXT("I don't really know what to say here, so let's just assume I told you everything and say goodbye. So... goodbye!")
            )
        )
    ); 

    creact_render( 
        "#creact-root",
        (creact_node_t[]){
            root,
            { .type = CREACT_NODE_TYPE_END }
        }
    );

    init_draggable_windows();
    init_article_links();
}

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
                "p:not(.window-title p), h1, h2",
                CR_STYLE_PAIR("padding-bottom", "10px")
            )
            CR_STYLE_FOR(
                "h1",
                CR_STYLE_PAIR("font-size", "30px")
            )
            CR_STYLE_FOR(
                "h2",
                CR_STYLE_PAIR("font-size", "25px")
            )
            CR_STYLE_FOR(
                ".article-card",
                CR_STYLE_PAIR("background-color", "black")
                CR_STYLE_PAIR("padding", "10px")
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
                    EL_ARTICLE_CARD("this-website-is-written-in-c", "demo 1", "so ehhh demo 1 This website is written in C. Hi, welcome to my little blog/website/corner/whatever (written in C!), I hope you'll find something useful here (you will not)!")
                )
            ) 
        ),
        EL_ARTICLE( 
            "This website is written entirelly in C",
            "this-website-is-written-in-c", "September 12, 2026",
            EL_HEADER(1, CR_TEXT("yes")) 
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

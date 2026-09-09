#include <stdio.h>

#include <creact/renderer.h>
#include <creact/tree-builder.h>

int main() {
    puts("Hi, so... ehhh... this website is written in the C programming language. Check its source out: https://github.com/gorciu-official/neocities");

    creact_remove_startup_notice();

    creact_node_t root = CR_ELEMENT(
        "div", CR_ATTRS(),
        CR_STYLE(
            CR_STYLE_FOR(
                "*", 
                CR_STYLE_PAIR("margin", "0")
                CR_STYLE_PAIR("padding", "0")
                CR_STYLE_PAIR("color", "white")
                CR_STYLE_PAIR("box-sizing", "border-box")
            )
            CR_STYLE_FOR(
                "main",
                CR_STYLE_PAIR("background-color", "black")
                CR_STYLE_PAIR("height", "100vh") // stupid compat fallback
                CR_STYLE_PAIR("height", "100dvh")
            )
        ),
        CR_ELEMENT(
            "main", CR_ATTRS(),
            CR_TEXT("hi") 
        )
    ); 
 
    creact_render( 
        "#creact-root",
        (creact_node_t[]){
            root,
            { .type = CREACT_NODE_TYPE_END }
        }
    );
}

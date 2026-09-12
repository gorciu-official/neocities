#pragma once

#include <creact/tree-builder.h>

#define EL_CENTER(...) \
    CR_ELEMENT( \
        "div", CR_ATTRS( \
            CR_ATTR("class", "center") \
        ), \
        __VA_ARGS__ \
    )

#define EL_LINK_OUT(target_url, ...) \
    CR_ELEMENT ( \
        "a", CR_ATTRS( \
            CR_ATTR("href", target_url), \
            CR_ATTR("target", "_blank") \
        ), __VA_ARGS__ \
    )

#define EL_PARAGRAPH(...) \
    CR_ELEMENT( \
        "p", CR_ATTRS(), \
        __VA_ARGS__ \
    )

#define EL_HEADER(level, ...) \
    CR_ELEMENT( \
        "h" #level, CR_ATTRS(), \
        __VA_ARGS__ \
    )

#define EL_ARTICLE_CARD(points_to, title, desc) \
    CR_ELEMENT( \
        "div", CR_ATTRS(), \
        CR_ELEMENT( \
            "div", CR_ATTRS( \
                CR_ATTR("class", "article-card"), \
                CR_ATTR("data-pointsto", points_to) \
            ), \
            EL_HEADER(2, CR_TEXT(title)), \
            EL_PARAGRAPH(CR_TEXT(desc)) \
        ) \
    )

#define EL_ARTICLE_CARDS(...) \
    CR_ELEMENT( \
        "div", CR_ATTRS( \
            CR_ATTR("class", "article-card-group") \
        ), \
        __VA_ARGS__ \
    )

#define EL_WINDOW(name, content) \
    CR_ELEMENT( \
        "div", CR_ATTRS( \
            CR_ATTR("class", "window hidden"), \
        ), \
        CR_ELEMENT( \
            "div", CR_ATTRS( \
                CR_ATTR("class", "window-title") \
            ), \
            EL_PARAGRAPH(CR_TEXT(name)), \
            CR_ELEMENT( \
                "span", CR_ATTRS( \
                    CR_ATTR("class", "window-close-btn") \
                ), \
                CR_TEXT("X") \
            ) \
        ), \
        content \
    )

#define EL_ARTICLE(name, id, published_on, ...) \
    EL_WINDOW( \
        name, \
        CR_ELEMENT( \
            "article", CR_ATTRS( \
                CR_ATTR("id", "article-" id), \
                CR_ATTR("class", "window-content") \
            ), \
            EL_HEADER(2, CR_TEXT(name)), \
            __VA_ARGS__ \
        ) \
    )

#define EL_CENTERED_IMAGE(url) \
    EL_CENTER( \
        CR_ELEMENT( \
            "img", CR_ATTRS( \
                "src", url, \
                "style", "max-width: 85%" \
            ) \
        ) \
    )

#define EL_UNORDERED_LIST(...) \
    CR_ELEMENT("ul", CR_ATTRS(), __VA_ARGS__)

#define EL_LIST_ENTRY(...) \
    CR_ELEMENT("li", CR_ATTRS(), __VA_ARGS__)

#pragma once

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

#define EL_ARTICLE_CARD(title, desc) \
    CR_ELEMENT( \
        "div", CR_ATTRS(), \
        CR_ELEMENT( \
            "div", CR_ATTRS( \
                CR_ATTR("class", "article-card") \
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

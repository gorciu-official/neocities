all:
	CREACT_WEBSITE_TITLE="gorciu's corner (v2)" make -C CReact

pull:
	git -C CReact pull --rebase

run: all 
	python3 -m http.server -d CReact/web

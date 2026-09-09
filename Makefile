all:
	make -C CReact

pull:
	git -C CReact pull --rebase

run: all 
	python3 -m http.server -d CReact/web

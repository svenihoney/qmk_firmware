build:
    util/docker_build.sh sofle_choc:svenivia

flash:
    util/docker_build.sh sofle_choc:svenivia:flash

buildm:
    util/docker_build.sh sofle_choc:svenimiryoku

flashm:
    util/docker_build.sh sofle_choc:svenimiryoku:flash

json:
    util/docker_cmd.sh qmk json2c keyboards/sofle_choc/keymaps/svenimiryoku/sveni_miryoku.json | head -n 25 > keyboards/sofle_choc/keymaps/svenimiryoku/keymap-json.h

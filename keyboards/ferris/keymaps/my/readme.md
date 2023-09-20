# hardware

count | part | from
------|------|-----
20x | keycap choc MBK pastel yellow | splitkb
20x | keycap choc MBK pastel green | splitkb
36x | switch kailh choc pink 20cN | splitkb
50x | hotswap socket kailh choc | splitkb
2x | Elite-C rev4 | splitkb
2x | mill max low profile socket | splitkb
2x | TRRS jack TH plug | splitkb
2x | TRRS jack TH 90° adapter | splitkb
1x | TRRS jack braided cable | splitkb
1x | PCB left+right halves | jlcpcb
1x | usb-c usb-c cable | amazon
1x | usb-c usb-a adapter | amazon
10x | rubber feet | amazon

# soldering

part | from
-----|-----
soldering iron+kit | amazon
soldering mat | amazon
solder 0.3mm no lead | amazon
solder 0.6mm no lead | amazon

# upstream

```sh
git remote add upstream https://github.com/qmk/qmk_firmware.git

git switch master
git pull upstream master
git push origin master

git switch dev
git merge --no-ff master
git push origin dev
```

# firmware

```sh
qmk doctor

qmk compile
ls ~/qmk_firmware/.build

# from root of qmk repo
make ferris/sweep:my:dfu-split-left
make ferris/sweep:my:dfu-split-right

qmk flash
```

Worker information
hostname: worker-jupiter-brain:31826d33-f9de-47bf-ae6c-8d87e9635da5
version: v2.0.0 https://github.com/travis-ci/worker/tree/ca6cb0c5d3920912b1c3acc87c44a5da2120a971
instance: bf76d5a8-9a03-448e-9e59-6d2f1dcfcde6:
startup: 1m14.610651903s
Build system information
Build language: cpp
Build group: stable
Build dist: precise

$ git clone --depth=50 --branch=master https://github.com/Gunn3r1995/glex.git Gunn3r1995/glex
Cloning into 'Gunn3r1995/glex'...
remote: Counting objects: 1347, done.
remote: Compressing objects: 100% (580/580), done.
remote: Total 1347 (delta 840), reused 1121 (delta 627), pack-reused 0
Receiving objects: 100% (1347/1347), 20.01 MiB | 1.64 MiB/s, done.
Resolving deltas: 100% (840/840), done.
Checking connectivity... done.
$ cd Gunn3r1995/glex
$ git checkout -qf 2a88ae36cedd19c9cbe213fbe2912041c2d79458
$ export CXX=g++
$ export CC=gcc
$ gcc --version
Configured with: --prefix=/Applications/Xcode.app/Contents/Developer/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 6.0 (clang-600.0.54) (based on LLVM 3.5svn)
Target: x86_64-apple-darwin13.4.0
Thread model: posix
$ if [ "$TRAVIS_OS_NAME" == "linux" ]; then echo "yes" |sudo apt-add-repository ppa:zoogie/sdl2-snapshots; fi
$ if [ "$TRAVIS_OS_NAME" == "linux" ]; then sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y; fi
$ if [ "$TRAVIS_OS_NAME" == "linux" ]; then sudo apt-get update -qq; fi
$ if [ "$TRAVIS_OS_NAME" == "linux" ]; then sudo apt-get install -y gcc-4.8 g++-4.8 libsdl-* libglm-dev libglew-dev libboost-all-dev libsdl2-dev; fi
$ if [ "$TRAVIS_OS_NAME" == "linux" ]; then sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90; fi
$ if [ "$TRAVIS_OS_NAME" == "osx" ]; then brew update; fi
Updated Homebrew from 77e2b755 to 9550f64c.
==> New Formulae
aap
abi-compliance-checker
aescrypt-packetizer
aeskeyfind
afl-fuzz
agda
agedu
aide
airspy
algernon
allegro
amazon-ecs-cli
amdatu-bootstrap
ammonite-repl
anjuta
ansible-cmdb
ansiweather
antigen
apache-archiva
apache-drill
apcupsd
apel
app-engine-go-32
app-engine-go-64
app-engine-java
app-engine-python
appledoc
apr
apr-util
aptly
archivemail
arpon
artifactory-cli-go
arx
asciinema
asio
aurora-cli
autocode
awf
aws-apigateway-importer
azure-cli
baobab
baresip
bash-preexec
bazel
bee
bgpdump
bitrise
blockhash
bltool
blucat
boot-clj
brotli
bwctl
bzr-fastimport
caddy
caf
cake
camlp4
carina
carthage
catimg
ccat
cctools
cdiff
cern-ndiff
cf
cfr-decompiler
chadwick
chaiscript
chapel
chinadns-c
choose
choose-gui
cidrmerge
cig
cjdns
clang-format
clang-omp
clearlooks-phenix
cless
clog
closure-linter
codec2
codemod
commonmark
consul
consul-template
corectl
corelocationcli
coturn
cpp-netlib
cppcms
cppformat
cpprestsdk
creduce
cromwell
cryptol
crystal-lang
crystax-ndk
ctunnel
curlish
curlpp
cvc4
cxxtest
dark-mode
davmail
dbxml
dcadec
dcd
deis
deisctl
delta
dependency-check
desk
desktop-file-utils
devd
devhelp
dex
dfix
dfmt
diffoscope
digitemp
distribution
dnscrypt-wrapper
dnstwist
docker-compose
docker-machine
docker-machine-parallels
docker-swarm
dockviz
doctl
double-conversion
dsd
dspdfviewer
duck
dupseek
dwarfutils
dxpy
ebook-tools
efl
eg
elementary
elm
embulk
envchain
envv
epeg
eralchemy
euler-py
evas-generic-loaders
evince
exact-image
exercism
extract_url
fabric
fb-adb
fcitx-remote-for-osx
fdk-aac-encoder
fetchmail
ffe
ffms2
fibjs
file-roller
finatra
fizsh
flatbuffers
flow
fluent-bit
flyway
fmpp
fobis
folly
fonttools
ford
fpp
fprobe
fq
fsevent_watch
fstar
fugu
fwup
galen
game-music-emu
gammaray
gasnet
gauge
gcovr
gdb
gdl
gdm
gdnsd
gdub
gedit
generate-json-schema
geocode-glib
get-flash-videos
gexiv2
gf-complete
ghex
ghq
gif2png
gifify
giflossy
gimme
git-credential-manager
git-fixup
git-fresh
git-hooks
git-lfs
git-octopus
git-plus
git-review
git-secrets
git-stree
git-subrepo
git-test
git-town
gitlab-ci-multi-runner
gitup
gjs
gjstest
glbinding
globe
glslang
glyr
gnatsd
gnome-builder
gnome-themes-standard
gnuradio
godep
gollum
gom
google-benchmark
goolabs
gor
gost
gotags
gowsdl
gpa
gperftools
gprof2dot
graphene
graphite2
groovysdk
gsar
gssh
gst-python
gst-validate
gstreamermm
gtk-mac-integration
gtkextra
gucharmap
gumbo-parser
gws
gxml
h2o
hackrf
hardlink-osx
hashcash
haskell-stack
hayai
hebcal
hh
highlighting-kate
homebrew/versions/android-ndk-r10c
homebrew/versions/android-ndk-r10d
homebrew/versions/ansible18
homebrew/versions/antlr3
homebrew/versions/apache-spark121
homebrew/versions/apache-spark131
homebrew/versions/apache-spark141
homebrew/versions/astyle204
homebrew/versions/bind99
homebrew/versions/boost150
homebrew/versions/boost155
homebrew/versions/boot2docker133
homebrew/versions/boot2docker141
homebrew/versions/boot2docker162
homebrew/versions/camlp5-606
homebrew/versions/cassandra20
homebrew/versions/cassandra22
homebrew/versions/cmake28
homebrew/versions/cmake30
homebrew/versions/cmake31
homebrew/versions/docker133
homebrew/versions/docker141
homebrew/versions/docker150
homebrew/versions/docker162
homebrew/versions/docker171
homebrew/versions/duplicity06
homebrew/versions/elasticsearch17
homebrew/versions/elasticsearch20
homebrew/versions/erlang-r17
homebrew/versions/freetds091
homebrew/versions/gcc5
homebrew/versions/gcc6
homebrew/versions/gdal111
homebrew/versions/gecode373
homebrew/versions/gegl02
homebrew/versions/gnupg21
homebrew/versions/gnuplot4
homebrew/versions/gnutls34
homebrew/versions/go13
homebrew/versions/go14
homebrew/versions/gradle20
homebrew/versions/gradle21
homebrew/versions/gradle221
homebrew/versions/gradle24
homebrew/versions/gradle26
homebrew/versions/gradle27
homebrew/versions/gradle28
homebrew/versions/hadoop25
homebrew/versions/hive010
homebrew/versions/hive011
homebrew/versions/influxdb08
homebrew/versions/iojs
homebrew/versions/isl014
homebrew/versions/jruby168
homebrew/versions/jruby1721
homebrew/versions/jruby9000
homebrew/versions/jython253
homebrew/versions/kettle54
homebrew/versions/kibana41
homebrew/versions/kibana42
homebrew/versions/ledger26
homebrew/versions/libidn2
homebrew/versions/libmongoclient-legacy
homebrew/versions/libpqxx3
homebrew/versions/libuv0
homebrew/versions/libxc21
homebrew/versions/libxml278
homebrew/versions/llvm36
homebrew/versions/llvm37
homebrew/versions/lua53
homebrew/versions/lz4r117
homebrew/versions/mapnik2
homebrew/versions/mariadb100
homebrew/versions/maven32
homebrew/versions/mongodb26
homebrew/versions/mono3
homebrew/versions/mysql56
homebrew/versions/nasm21106
homebrew/versions/nettle3
homebrew/versions/nifi021
homebrew/versions/node010
homebrew/versions/node012
homebrew/versions/node4-lts
homebrew/versions/objective-caml312
homebrew/versions/openssl101
homebrew/versions/pandoc-citeproc05
homebrew/versions/pandoc1131
homebrew/versions/phantomjs198
homebrew/versions/play13
homebrew/versions/postgresql93
homebrew/versions/protobuf250
homebrew/versions/protobuf260
homebrew/versions/qt52
homebrew/versions/redis26
homebrew/versions/redis28
homebrew/versions/ruby187
homebrew/versions/ruby21
homebrew/versions/saxon6
homebrew/versions/selenium-server-standalone245
homebrew/versions/solr4
homebrew/versions/sonar4
homebrew/versions/swig2
homebrew/versions/swig304
homebrew/versions/syncthing010
homebrew/versions/thrift090
homebrew/versions/unison240
homebrew/versions/v8-315
homebrew/versions/virtuoso616
homebrew/versions/zeromq405
honcho
http-parser
i2p
i2util
ibex
icdiff
icecream
icmake
id3ed
idris
imagejs
imessage-ruby
imgur-screenshot
internetarchive
ipfs
iproute2mac
ipsumdump
jdnssec-tools
jenkins-job-builder
jenv
jerasure
jlog
jooby-bootstrap
joshua
jpeg-archive
jpegrescan
json-fortran
jsoncpp
jsonnet
jsonschema2pojo
julius
juman
jvgrep
kafkacat
kapacitor
karn
kettle
khal
khard
kibana
kitchen-sync
kore
kotlin
kubernetes-cli
lastpass-cli
launchdns
lcab
ldid
lfe
libagar
libbladerf
libbpg
libcdr
libchamplain
libdbi
libepoxy
liberasurecode
libfabric
libfixposix
libforensic1394
libfreehand
libgdata
libghthash
libgig
libgit2-glib
libgraphqlparser
libgweather
libgxps
libhdhomerun
libhttpserver
libical-glib
libilbc
libiodbc
libiomp
libjson-rpc-cpp
libmill
libnfs
libpagemaker
libpeas
libpointing
libprotoident
libquantum
librdkafka
librest
libsoundio
libsoxr
libspectre
libspnav
libstatgrab
libuecc
libwandevent
libwebm
libxdg-basedir
libxmp-lite
lsh
ltl2ba
luyten
m2c
mailhog
makefile2graph
mandoc
mbedtls
mdds
mdk
mediaconch
megatools
memo
mergepbx
metabase
metashell
mg3a
miller
minisign
miruo
mitie
mlogger
mobiledevice
mockserver
modgit
moe
mosml
moz-git-tools
mp3unicode
mpich
mpv
mpw
mstch
multirust
mupdf-tools
muttils
mvnvm
mvtools
mycli
mydumper
mypy
mysql-sandbox
mysqltuner
nailgun
natalie
nave
ne
negfix8
nfdump
nghttp2
nifi
nikto
nim
node-build
nodeenv
nomad
norm
nq
nyancat
oauth2_proxy
ocaml
odo
odt2txt
offlineimap
ompl
one-ml
ooniprobe
open-jtalk
open-zwave
opendbx
openh264
openhmd
openvdb
openwsman
osquery
otto
pacapt
packer
pacvim
passpie
pcap_dnsproxy
pcre2
pcsc-lite
pdf-redact-tools
peco
pegtl
pgcli
pgloader
pgroonga
pillar
pinentry-mac
pipes-sh
pjproject
pkcrack
pkgdiff
pla
planck
pldebugger
ploticus
pod2man
pond
ponyc
postgrest
powerline
ppl
pre-commit
prefixsuffix
prettyping
procmail
procyon-decompiler
progress
protobuf-swift
psql2csv
puddletag
pugixml
purescript
pushpin
pwntools
pyenv-pip-migrate
qjackctl
qpm
qriollo
queequeg
rack
racket
rancher-compose
rapidjson
ratfor
rbenv-bundle-exec
rbenv-bundler-ruby-version
redir
redis-leveldb
redpen
redshift
rem
remarshal
restund
rexster
rgxg
riemann-client
rtags
rtmidi
rubberband
saldl
sblim-sfcc
sbtenv
scalaenv
scalariform
scmpuff
scour
scriptcs
scw
sdedit
serveit
sfk
sha2
shairport
shairport-sync
shc
shibboleth-sp
shml
shpotify
sickrage
sift
sile
simple-amqp-client
sjk
skinny
slackcat
smali
smpeg
smpeg2
snag
snappystream
sngrep
snow
softhsm
sourcekitten
spaceman-diff
spandsp
sparse
speech-tools
sphinx-doc
spoof-mac
sqlite-analyzer
sqliteodbc
sqtop
src
srclib
ssllabs-scan
sslmate
sslyze
sstp-client
stash-cli
stdman
stlink
stoken
stormssh
suil
supersonic
swagger-codegen
swift
swiftgen
swiftlint
syncthing-inotify
synscan
syntaxerl
systemc
tachyon
tailor
takt
tasksh
taylor
tccutil
tcpkali
tcpstat
td
telegraf
testssl
texmath
textql
tgui
thefuck
tidy-html5
tippecanoe
titlecase
trace2html
trr
tvnamer
twoping
ucommon
ucspi-tools
uhd
unarj
uni2ascii
unibilium
unicorn
unyaffs
upscaledb
utf8proc
validns
vamp-plugin-sdk
vapoursynth
vault
vavrdiasm
vc4asm
vdirsyncer
vegeta
viennacl
viewvc
vmtouch
vnu
vpcs
vultr
wakatime-cli
walkmod
wartremover
watch-sim
webarchiver
webkitgtk
weboob
websocketd
wellington
whatmp3
why3
wifi-password
wiki
wires
wirouter_keyrec
with-readline
wolfssl
woof
wslay
wsmancli
xalan-c
xar-mackyle
xdot
xhyve
xmake
xonsh
xsd
xsp
xxhash
yank
yash
yelp-tools
yelp-xsl
ykneomgr
z3
zanata-client
zero-install
zimg
zita-convolver
zmqpp
zorba
zurl
zzz
==> Updated Formulae
a2ps					apngasm
a52dec					apollo
aacgain					apparix
aalib					appscale-tools
aamath					apt-cacher-ng
aardvark_shell_utils			apt-dater
abcde					aqbanking
abcl					arabica
abcm2ps					arangodb
abcmidi					archey
abduco					argp-standalone
abnfgen					argtable
abook					argus
ace					argus-clients
aces_container				argyll-cms
ack					aria2
acme					arm
acpica					arp-scan
activemq				arp-sk
activemq-cpp				arping
admesh					arpoison
adns					arss
adplug					artifactory
advancecomp				ascii
aescrypt				asciidoc
aespipe					asciitex
afflib					asm6
afio					asn1c
afsctool				aspcud
aften					aspell
aget					assimp
aggregate				astyle
aha					at-spi2-atk
ahcpd					at-spi2-core
aiccu					atdtool
aircrack-ng				aterm
akka					atf
alac					atk
aldo					atkmm
algol68g				atomicparsley
align					atool
alpine					ats2-postiats
alure					aubio
amap					audiofile
amtterm					augeas
analog					auto-scaling
android-ndk				autobench
android-platform-tools			autoconf
android-sdk				autoconf-archive
ansible					autoenv
ansifilter				autogen
ant					autojump
ant-contrib				automake
antiword				automoc4
antlr					automysqlbackup
anttweakbar				autopano-sift-c
aoeui					autopsy
apache-forrest				autossh
apache-opennlp				autotrace
apache-spark				avce00
apachetop				avian
ape					avidemux
apg					aview
apgdiff					avra
apib					avrdude
apktool					avro-c
avro-cpp				bmake
avro-tools				bmon
aws-cfn-tools				bogofilter
aws-cloudsearch				bokken
aws-elasticache				bonnie++
aws-elasticbeanstalk			boost
aws-sns-cli				boost-bcp
awscli					boost-build
axel					boost-python
b43-fwcutter				boot2docker
babeld					botan
babl					box2d
backupninja				boxes
bacula-fd				bpm-tools
bagit					brag
balance					brew-gem
bam					brew-pip
bar					briss
base64					bro
basex					browser
bash					bsdconv
bash-completion				bsdiff
bash-git-prompt				bsdmake
bashdb					bsdsfv
bashish					bsponmpi
batik					btparse
bats					btpd
bazaar					buildapp
bbcolors				bulk_extractor
bbe					bullet
bbftp-client				bup
bchunk					burl
bcpp					burp
bcrypt					bvi
bdw-gc					bwm-ng
beansdb					byacc
beanstalk				byobu
bear					c-ares
beecrypt				c-kermit
berkeley-db				cabal-install
berkeley-db4				cabextract
betty					cabocha
bfg					cadaver
bgpq3					cadubi
bgrep					cairo
bib-tool				cairomm
bibclean				calabash
bibtex2html				calc
bibtexconv				calcurse
bibutils				camellia
bigdata					camlistore
bigloo					camlp5
bind					capnp
binutils				capstone
binwalk					cask
bip					casperjs
bison					cassandra
bitchx					cattle
bitlbee					caudec
bittwist				cayley
blahtexml				cbmbasic
blazeblogger				cc65
blink1					ccache
blitz					ccal
blitzwave				ccd2iso
blueutil				ccextractor
cclive					cln
ccm					cloc
cconv					clockywock
ccrypt					clojurescript
cctools-headers				cloog
ccze					closure-compiler
cd-discid				cloud-watch
cdargs					cloudbees-sdk
cdb					clozure-cl
cdecl					clpbar
cdk					clucene
cdlabelgen				clutter
cdparanoia				clutter-gst
cdpr					clutter-gtk
cdrdao					cmake
cdrtools				cmatrix
center-im				cmigemo
cereal					cmocka
ceylon					cmockery
cfengine				cmockery2
cfitsio					cmu-pocketsphinx
cflow					cmu-sphinxbase
cfv					cmuclmtk
cgal					cmus
cgdb					cntlm
cgrep					coccinelle
cgvg					cocot
charm-tools				coda-cli
chcase					codequery
cheat					cogl
check					coin
check_postgres				collada-dom
checkbashisms				collectd
checkstyle				colordiff
cherokee				colormake
chgems					colorsvn
chibi-scheme				colortail
chicken					compcert
chipmunk				compface
chisel					concurrencykit
chkrootkit				confuse
chmlib					conserver
chordii					contacts
chromaprint				convertlit
chrome-cli				convmv
chromedriver				cookiecutter
chruby					coq
chruby-fish				coreutils
chuck					corkscrew
cifer					couchdb
cimg					couchdb-lucene
cityhash				couchpotatoserver
cksfv					cowpatty
clamav					cowsay
clamz					cpanminus
clasp					cpansearch
class-dump				cpmtools
classads				cppcheck
clean					cppi
clens					cpptest
clhep					cppunit
clib					cpputest
cliclick				cproto
clipper					cpulimit
clipsafe				cputhrottle
clisp					cracklib
crash					ddrescue
crf++					debianutils
crm114					deheader
cronolog				deja-gnu
crosstool-ng				denominator
crunch					depqbf
crush-tools				detox
cryptopp				devil
cscope					devtodo
csfml					dex2jar
csmith					dfc
cspice					dfu-programmer
css-crush				dfu-util
cssembed				dhcpdump
csshx					dhcping
csup					dhex
csv-fix					di
csvprintf				dialog
csync					dict
ctags					diction
ctail					dieharder
ctemplate				diff-pdf
ctl					diffuse
ctorrent				dirac
cuetools				dircproxy
cunit					direnv
cups-pdf				dirmngr
curaengine				dirt
curl					disco
cutter					discodex
cuty_capt				discount
cvs					disktype
cvs2svn					distcc
cvsps					ditaa
cvsutils				djbdns
cvsync					djview4
cweb					djvu2pdf
czmq					djvulibre
d-bus					dmalloc
daemon					dmd
daemonize				dmtx-utils
daemonlogger				dns2tcp
daemontools				dnscrypt-proxy
dante					dnsmap
daq					dnsmasq
dar					dnsperf
darcs					dnsrend
darkhttpd				dnstop
darkice					dnstracer
darkstat				docbook
dash					docbook-xsl
dasm					docbook2x
dateutils				docker
datomic					dockutil
davix					doitlive
dbacl					dos2unix
dbus-glib				doublecpp
dc3dd					doubledown
dcal					dovecot
dcfldd					doxygen
dcled					doxymacs
dcmtk					dpkg
dcraw					drake
ddar					drip
ddate					dromeaudio
ddclient				dropbear
dsh					epubcheck
dsocks					erlang
dtach					es
dtc					esniper
dterm					esound
dtrx					espeak
dub					etcd
duff					etl
duo_unix				ettercap
duplicity				euca2ools
duply					evas
duti					eventlog
dvd+rw-tools				ex-vi
dvdauthor				exempi
dvdbackup				exenv
dvdrtools				exif
dvorak7min				exiftags
dvtm					exiftool
dwarf					exim
dwatch					exiv2
dwdiff					exodriver
dxflib					expat
dyld-headers				eye-d3
dylibbundler				ezlupdate
dynamips				ezstream
dynamodb-local				f3
e2fsprogs				faac
easy-git				faad2
ec2-ami-tools				fail2ban
ec2-api-tools				fakeroot
ecasound				falcon
echoprint-codegen			fantom
ecj					fasd
ecl					fastbit
ecm					fastjar
edelta					fatsort
editorconfig				fb-client
ee					fbida
eet					fcgi
eigen					fcgiwrap
eina					fcrackzip
ejabberd				fdclone
ejdb					fdk-aac
ekg2					fdupes
ekhtml					fetch-crl
elasticsearch				fex
elb-tools				ffind
elinks					ffmbc
elixir					ffmpeg
elixir-build				ffmpeg2theora
emacs					ffmpegthumbnailer
emacs-clang-complete-async		fftw
embryo					ficy
emscripten				figlet
enca					findbugs
enchant					findutils
enet					fio
engine_pkcs11				fish
enscript				fits
ent					flac
entr					flac123
eot-utils				flactag
epic5					flake
eprover					flashrom
epsilon					flasm
epstool					flawfinder
fleet-db				gcutil
fleetctl				gd
flex					gdal
flickcurl				gdal-grass
flow-tools				gdbm
flowgrind				gdk-pixbuf
fltk					gdmap
fluid-synth				gearman
flvmeta					gecode
flvstreamer				gegl
fmdiff					genders
fon-flash-cli				gengetopt
fondu					genstats
fontconfig				geocouch
fontforge				geogit
fop					geographiclib
forego					geoip
foremost				geoipupdate
fortune					geos
fossil					geoserver
fourstore				getdns
fpc					getmail
fping					gettext
frag_find				getxbook
fragroute				gflags
freealut				gforth
freediameter				gh
freeimage				ghc
freeipmi				ghi
freeling				ghostscript
freeradius-server			gibbslda
freeswitch				gibo
freetds					giflib
freetype				gifsicle
freexl					ginac
frege					gist
frei0r					gistit
frescobaldi				git
fribidi					git-annex
fsh					git-archive-all
fsw					git-cal
fswatch					git-cola
ftgl					git-crypt
ftimes					git-extras
ftjam					git-flow
funcoeszz				git-flow-avh
fuseki					git-ftp
fuzzy-find				git-gerrit
fwknop					git-imerge
fzf					git-integration
g2					git-multipush
gabedit					git-now
gaffitter				git-number
gambit-scheme				git-open
gammu					git-sh
ganglia					git-ssh
garmintools				git-tf
gauche					git-tracker
gaul					git-url-sub
gawk					gitbucket
gbdfed					giter8
gcab					github-release
gcal					gitslave
gcc					gl2ps
gconf					glassfish
gcore					glew
glib					graphviz
glib-networking				grass
glibmm					grc
glide					grepcidr
glm					grib-api
global					griffon
globus-toolkit				gringo
glog					grok
gloox					groonga
glui					groonga-normalizer-mysql
gmail-backup				groovy
gmediaserver				groovyserv
gmime					growly
gmp					grsync
gmtl					gsasl
gnome-common				gsettings-desktop-schemas
gnome-doc-utils				gsl
gnome-icon-theme			gsoap
gnu-apl					gssdp
gnu-barcode				gst-libav
gnu-cobol				gst-plugins-bad
gnu-getopt				gst-plugins-base
gnu-indent				gst-plugins-good
gnu-prolog				gst-plugins-ugly
gnu-sed					gstreamer
gnu-smalltalk				gti
gnu-tar					gtk+
gnu-time				gtk+3
gnu-typist				gtk-doc
gnu-units				gtk-engines
gnu-which				gtk-gnutella
gnupg					gtk-murrine-engine
gnupg-pkcs11-scd			gtkdatabox
gnupg2					gtkglext
gnuplot					gtkmm
gnustep-make				gtkmm3
gnutls					gtksourceview
go					gtksourceview3
goaccess				gtkspell3
gobject-introspection			gtmess
gocr					gts
goffice					guile
golo					gupnp
goocanvas				gupnp-av
google-sparsehash			gupnp-tools
google-sql-tool				gvp
gosu					gwenhywfar
gource					gwt
gpac					gwyddion
gpg-agent				gzrt
gpgme					h2
gphoto2					h264bitstream
gplcver					hachoir-metadata
gpm					hadoop
gpp					halibut
gpsbabel				hamlib
gpsd					haproxy
gpsim					harbour
gptsync					hardlink
gputils					harfbuzz
gqlplus					hashpump
gqview					haxe
gradle					hbase
grails					headphones
grap					hello
graphicsmagick				help2man
henplus					homebrew/versions/grails21
hercules				homebrew/versions/grails22
heroku-toolbelt				homebrew/versions/grails223
herrie					homebrew/versions/grails224
hevea					homebrew/versions/grails23
hexcurse				homebrew/versions/gsl114
hexedit					homebrew/versions/gst-ffmpeg010
hfsutils				homebrew/versions/gst-plugins-bad010
hg-flow					homebrew/versions/gst-plugins-base010
hicolor-icon-theme			homebrew/versions/gst-plugins-good010
hidapi					homebrew/versions/gst-plugins-ugly010
highlight				homebrew/versions/gst-python010
hilite					homebrew/versions/gst-rtsp010
hiredis					homebrew/versions/gstreamer010
hive					homebrew/versions/guile18
hoedown					homebrew/versions/hadoop0202
homebank				homebrew/versions/hadoop121
homebrew/versions/allegro4		homebrew/versions/hdf4
homebrew/versions/android-ndk-r9d	homebrew/versions/imagemagick-ruby186
homebrew/versions/ansible14		homebrew/versions/isl011
homebrew/versions/antlr2		homebrew/versions/isl012
homebrew/versions/appledoc20		homebrew/versions/jboss-as5
homebrew/versions/appledoc21		homebrew/versions/jboss-forge1
homebrew/versions/appledoc22		homebrew/versions/jenkins-lts
homebrew/versions/autoconf213		homebrew/versions/jetty76
homebrew/versions/autoconf264		homebrew/versions/jetty8
homebrew/versions/automake112		homebrew/versions/jpeg6b
homebrew/versions/bash-completion2	homebrew/versions/jpeg9
homebrew/versions/bison27		homebrew/versions/json-c010
homebrew/versions/boost149		homebrew/versions/kafka080
homebrew/versions/cassandra-0.6		homebrew/versions/leptonica169
homebrew/versions/cassandra10		homebrew/versions/libcouchbase1
homebrew/versions/cassandra12		homebrew/versions/libdvdcss12
homebrew/versions/clojure14		homebrew/versions/libgee08
homebrew/versions/cloog-ppl015		homebrew/versions/libmpc08
homebrew/versions/cloog018		homebrew/versions/libotr4
homebrew/versions/coq83			homebrew/versions/libpng12
homebrew/versions/cvsps2		homebrew/versions/llvm-gcc28
homebrew/versions/doxygen1831		homebrew/versions/llvm33
homebrew/versions/drush4		homebrew/versions/llvm34
homebrew/versions/drush5		homebrew/versions/llvm35
homebrew/versions/eigen2		homebrew/versions/log4cplus10
homebrew/versions/erlang-r13		homebrew/versions/maven2
homebrew/versions/erlang-r14		homebrew/versions/maven30
homebrew/versions/erlang-r15		homebrew/versions/maven31
homebrew/versions/erlang-r16		homebrew/versions/mkvtoolnix58
homebrew/versions/gawk3			homebrew/versions/mongodb24
homebrew/versions/gcc43			homebrew/versions/mpfr2
homebrew/versions/gcc44			homebrew/versions/mysql51
homebrew/versions/gcc45			homebrew/versions/mysql55
homebrew/versions/gcc46			homebrew/versions/node04
homebrew/versions/gcc47			homebrew/versions/node06
homebrew/versions/gcc48			homebrew/versions/node08
homebrew/versions/gcc49			homebrew/versions/nu0
homebrew/versions/giflib5		homebrew/versions/open-mpi16
homebrew/versions/git-tf-2.0.2		homebrew/versions/openjpeg20
homebrew/versions/glfw2			homebrew/versions/openjpeg21
homebrew/versions/glfw3			homebrew/versions/openssl098
homebrew/versions/gmp4			homebrew/versions/percona-server55
homebrew/versions/go12			homebrew/versions/perl514
homebrew/versions/gradle110		homebrew/versions/perl516
homebrew/versions/gradle112		homebrew/versions/perl518
homebrew/versions/gradle16		homebrew/versions/phantomjs17
homebrew/versions/gradle18		homebrew/versions/phantomjs182
homebrew/versions/grails13		homebrew/versions/phantomjs192
homebrew/versions/grails20		homebrew/versions/play12
homebrew/versions/play22		hyperspec
homebrew/versions/postgis15		iat
homebrew/versions/postgis20		ical-buddy
homebrew/versions/postgresql8		icarus-verilog
homebrew/versions/postgresql9		icbirc
homebrew/versions/postgresql91		ice
homebrew/versions/postgresql92		icecast
homebrew/versions/povray36		icon
homebrew/versions/ppl011		icon-naming-utils
homebrew/versions/ppl10			icoutils
homebrew/versions/protobuf240a		icu4c
homebrew/versions/protobuf241		id3lib
homebrew/versions/rabbitmq30		id3tool
homebrew/versions/raptor1		id3v2
homebrew/versions/redis1310		idcomments
homebrew/versions/redis24		ideviceinstaller
homebrew/versions/riak132		idnits
homebrew/versions/ruby182		idutils
homebrew/versions/ruby186		ievms
homebrew/versions/ruby192		ifstat
homebrew/versions/ruby193		iftop
homebrew/versions/ruby20		ii
homebrew/versions/scala210		ike-scan
homebrew/versions/scala29		ilmbase
homebrew/versions/solr14		imagemagick
homebrew/versions/solr36		imagesnap
homebrew/versions/squid2		imageworsener
homebrew/versions/subversion16		imap-uw
homebrew/versions/subversion17		imapfilter
homebrew/versions/tomcat6		imapsync
homebrew/versions/tomcat7		imlib2
homebrew/versions/unison232		influxdb
homebrew/versions/valgrind36		iniparser
homebrew/versions/valgrind38		innoextract
homebrew/versions/varnish3		innotop
homebrew/versions/zeromq22		ino
homebrew/versions/zeromq3		inspircd
homebrew/versions/zeromq32		intercal
horndis					intltool
hornetq					io
hostdb					iodine
hping					ioke
hqx					ioping
hr					ios-class-guard
ht					ios-sim
html-xml-utils				ios-webkit-debug-proxy
html2text				iozone
htmlcleaner				ip_relay
htmlcompressor				ipbt
htmlcxx					ipcalc
htmldoc					iperf
htop-osx				iperf3
htpdate					iphotoexport
http_load				ipinfo
httperf					ipmitool
httpie					ipmiutil
httping					iprint
httpry					ipv6calc
httptunnel				ipv6toolkit
httrack					ircd-hybrid
hub					ircd-irc2
hubflow					ircii
hugo					irods
hunspell				irrlicht
hydra					irrtoolset
hyperestraier				irssi
isc-dhcp				juju
isl					juju-quickstart
iso-codes				jvmtop
ispc					jython
ispell					kafka
isync					kakasi
itex2mml				kanif
itpp					kawa
itstool					kdiff3
ivy					keepassc
jack					kes
jags					kestrel
jailkit					keybase
jam					keychain
jansson					kimwitu++
jasmin					kite
jasper					kjell
javarepl				knock
jbake					knot
jbig2dec				known_hosts
jbig2enc				konoha
jbigkit					kqwait
jboss-as				ksh
jboss-forge				kstart
jcal					ktoblzcheck
jed					kvazaar
jemalloc				kyoto-cabinet
jena					kyoto-tycoon
jenkins					kytea
jerm					kyua
jetty					l-smash
jetty-runner				lablgtk
jhead					lame
jhiccup					languagetool
jigdo					lasi
jing					lastfmfpclient
jless					lastfmlib
jmeter					laszip
jmxtrans				latex2html
jnettop					latex2rtf
joe					launch
john					launch4j
john-jumbo				lbdb
jove					lbzip2
jp2a					lcdf-typetools
jpeg					lcdproc
jpeg-turbo				lci
jpeginfo				lcov
jpegoptim				lcrack
jq					ld64
jrnl					ldapvi
jruby					ldc
js-test-driver				ldns
jsawk					le
jsdoc-toolkit				leafnode
jsdoc3					ledger
jshon					ledit
jslint4java				legit
jsmin					leiningen
json-c					lemon
json-glib				lensfun
json_spirit				leptonica
jsonpp					lesspipe
jsvc					lesstif
judy					leveldb
juise					lft
lftp					libfishsound
lha					libfixbuf
lhasa					libflowmanager
lib3ds					libfreefare
libaacs					libfreenect
libagg					libftdi
libantlr3c				libftdi0
libao					libgadu
libarchive				libgaiagraphics
libart					libgcrypt
libass					libgda
libassuan				libgee
libatomic_ops				libgeotiff
libav					libgetdata
libb2					libgfshare
libbind					libgit2
libbinio				libglade
libbluray				libglademm
libbs2b					libgnomecanvas
libbson					libgnomecanvasmm
libbtbb					libgpg-error
libcaca					libgphoto2
libcanberra				libgroove
libcapn					libgsf
libcddb					libgsm
libcdio					libgtop
libcec					libharu
libcello				libhid
libcmph					libical
libcoap					libicns
libconfig				libid3tag
libcouchbase				libident
libcroco				libidl
libcsv					libidn
libcue					libimobiledevice
libcuefile				libinfinity
libdaemon				libiptcdata
libdap					libiscsi
libdbusmenu-qt				libkate
libdc1394				libkml
libdca					libksba
libdiscid				liblacewing
libdmtx					liblas
libdnet					liblastfm
libdrawtext				liblinear
libdshconfig				liblo
libdsk					liblockfile
libdv					liblqr
libdvbpsi				libltc
libdvdcss				liblunar
libdvdnav				liblwgeom
libdvdread				libmaa
libebml					libmagic
libebur128				libmarisa
libechonest				libmatroska
libelf					libmaxminddb
libestr					libmemcached
libetonyek				libmetalink
libev					libmicrohttpd
libevent				libmikmod
libewf					libming
libexif					libmms
libexosip				libmodbus
libextractor				libmodplug
libfaketime				libmongoclient
libffi					libmonome
libmowgli				libsmf
libmp3splt				libsmi
libmpc					libsndfile
libmpd					libsodium
libmpdclient				libsoup
libmpeg2				libspatialite
libmrss					libspiro
libmspub				libssh
libmtp					libssh2
libmusicbrainz				libstfl
libmxml					libstrophe
libnatpmp				libstxxl
libnet					libsvg
libnfc					libsvg-cairo
libnice					libsvm
libnids					libswiften
libntlm					libtar
libnxml					libtasn1
liboauth				libtecla
libodbc++				libtermkey
libodfgen				libtess2
libofx					libtextcat
libogg					libtiff
liboil					libtins
libopendkim				libtomcrypt
libopennet				libtommath
liboping				libtool
libopkele				libtorrent
libosip					libtorrent-rasterbar
libotr					libtrace
libowfat				libunistring
libp11					libunwind-headers
libpano					libupnp
libpcl					libusb
libpgm					libusb-compat
libplist				libusrsctp
libpng					libutf
libpoker-eval				libuv
libpqxx					libuvc
libpst					libvbucket
libpuzzle				libvidstab
libqalculate				libvirt
libqglviewer				libvisio
libquicktime				libvo-aacenc
libquvi					libvoikko
librasterlite				libvorbis
libraw					libvpx
librcsc					libwbxml
libre					libwebsockets
libreadline-java			libwmf
librem					libwpd
libreplaygain				libwpg
libresample				libwps
libressl				libxc
librevenge				libxdiff
librsvg					libxmi
librsync				libxml++
librtlsdr				libxml2
libsamplerate				libxmlsec1
libsass					libxmp
libscrypt				libxslt
libsecret				libxspf
libshout				libyaml
libsigc++				libyubikey
libsigsegv				libzdb
libslax					libzip
libzzip					mailutils
lifelines				mairix
lightning				makedepend
lighttpd				makeicns
lilv					makensis
link-grammar				makepkg
linklint				makepp
links					makeself
liquibase				mal4s
liquidprompt				malaga
litmus					malbolge
little-cms				man2html
little-cms2				mapnik
lldpd					mapserver
llvm					mariadb
lmdb					markdown
lnav					marst
lockrun					masscan
log4c					mat
log4cplus				matlab2tikz
log4cpp					maven
log4cxx					maven-shell
log4shib				mawk
logcheck				mbelib
logentries				mboxgrep
logrotate				mcabber
logstalgia				mcpp
logstash				mcrypt
logtalk					md
lolcode					md5deep
lorem					md5sha1sum
loudmouth				mda-lv2
lout					mdbtools
lpc21isp				mdf2iso
lrdf					mdp
lrzip					mdr
lrzsz					mdxmini
lsdvd					mecab
lsyncd					mecab-ipadic
ltc-tools				mecab-jumandic
lua					mecab-ko
lua51					mecab-ko-dic
luabind					mecab-unidic
luajit					media-info
luciddb					mediatomb
lutok					megacmd
luvit					memcache-top
lv					memcached
lv2					memcacheq
lwtools					memtester
lxsplit					menhir
lynis					mercurial
lynx					mercury
lysp					mergelog
lz4					mesos
lzip					metaproxy
lzlib					mfcuk
lzo					mfoc
lzop					mftrace
mac-robber				mg
mackup					mhash
macvim					midgard2
mad					midicsv
madplay					midnight-commander
mahout					mighttpd2
mailcheck				mikmod
mimms					mpdas
minbif					mpdscribble
minicom					mpdviz
minidjvu				mpegdemux
minidlna				mpfi
minimodem				mpfr
minisat					mpg123
minised					mpg321
miniupnpc				mpgtx
minizinc				mplayer
minizip					mplayershell
minuit2					mpop
miredo					mpssh
mitmproxy				mr
mjpegtools				mrtg
mkclean					mruby
mkcue					msdl
mksh					msgpack
mktorrent				msitools
mkvalidator				msktutil
mkvdts2ac3				msmtp
mkvtomp4				mspdebug
mkvtoolnix				mtools
mldonkey				mtr
mlt					mu
mm-common				multimarkdown
mmix					multitail
mmsrip					muparser
mmv					musepack
mobile-shell				mussh
moc					mutt
moco					mvptree
modman					mysql
modules					mysql++
mogenerator				mysql-cluster
mon					mysql-connector-c
monetdb					mysql-connector-c++
mongo-c					mysql-search-replace
mongodb					mytop
mongoose				n
mongrel2				nacl
mongroup				nagios
monit					nagios-plugins
monkeysphere				namazu
mono					namebench
monotone				nanomsg
montage					nanopb-generator
moreutils				nant
mosquitto				narwhal
most					nasm
movgrab					naturaldocs
mozilla-addon-sdk			nbimg
mozjpeg					ncdc
mp3blaster				ncdu
mp3cat					ncftp
mp3check				ncmpc
mp3gain					ncmpcpp
mp3info					ncp
mp3splt					ncrack
mp3val					ndiff
mp3wrap					ndpi
mp4v2					neko
mpack					neo4j
mpc					neon
mpck					nesc
mpd					net-snmp
netcat					open-babel
netcat6					open-cobol
netpbm					open-mesh
netperf					open-mpi
nettle					open-ocd
newlisp					open-scene-graph
newsbeuter				open-sp
newt					open-vcdiff
nexus					openal-soft
nfcutils				opencbm
nginx					opencc
ngircd					opencolorio
ngrep					openconnect
ngrok					opencore-amr
ngspice					opendetex
nickle					openexr
nicovideo-dl				openjpeg
ninja					openlitespeed
ninja-ide				openrtsp
nkf					opensaml
nload					opensc
nmap					openslide
node					openslp
nodebrew				openssl
nodenv					openvpn
nordugrid-arc				ophcrack
normalize				optipng
notmuch					opus
noweb					opus-tools
npth					opusfile
nrg2iso					orbit
nrpe					orc
nsd					orfeo
nspr					orientdb
nsq					orpie
nss					ortp
ntl					oscats
ntopng					osh
nu					osm-pbf
num-utils				osm2pgrouting
nut					osm2pgsql
nutcracker				osmosis
nuttcp					osslsigncode
nvi					ossp-uuid
nvm					osxfuse
nylon					osxutils
nzbget					owamp
oath-toolkit				owfs
objc-codegenutils			p0f
objc-run				p11-kit
ocamlsdl				p7zip
ocp					pakchois
ocrad					pam_yubico
ode					pandoc
oggz					pandoc-citeproc
ogmtools				pango
ohcount					pangomm
ola					pangox-compat
olsrd					paperkey
omega					paps
omniorb					par
ondir					par2
onepass					parallel
onetime					parrot
oniguruma				partio
opam					pass
passenger				pipemeter
pastebinit				pit
patchutils				pius
pax-construct				pixman
pax-runner				pixz
pazpar2					pk
pbc					pkcs11-helper
pbc-sig					pkg-config
pbrt					pktanon
pbzip2					plan9port
pcal					plantuml
pce					platypus
pcre					plenv
pcre++					plod
pdal					plotutils
pdf2htmlex				plowshare
pdf2json				plplot
pdf2svg					plustache
pdfcrack				plzip
pdfgrep					pmccabe
pdflib-lite				pmd
pdftohtml				pmdmini
pdksh					pms
pdns					png++
pdnsd					png2ico
pdnsrec					pngcheck
pdsh					pngcrush
peervpn					pngnq
peg					pngpaste
peg-markdown				pngquant
perceptualdiff				poco
percona-server				podiff
percona-toolkit				podofo
perl					points2grid
perl-build				polipo
pev					polygen
pex					polyml
pg_top					ponysay
pgbadger				poppler
pgbouncer				popt
pgdbf					portaudio
pgformatter				portmidi
pgpdump					poster
pgpool-ii				postgis
pgrouting				postgres-xc
pgtap					postgresql
pgtune					postmark
phantomjs				potrace
phash					pound
phoon					povray
phoronix-test-suite			pow
physfs					powerman
pianobar				ppss
pianod					predictionio
picoc					premake
picocom					primesieve
picolisp				prips
pidcat					privoxy
pidgin					probatron4j
pidof					proctools
pig					profanity
pigz					proftpd
pike					proguard
pincaster				proj
pinentry				proof-general
pipebench				protobuf
protobuf-c				qtplay
proxychains-ng				quantlib
proxytunnel				quassel
ps2eps					quazip
psftools				quex
psgrep					quilt
psqlodbc				quotatool
pssh					quvi
pstoedit				qwt
pstree					qwtpolar
psutils					qxmpp
ptex					r3
pth					rabbitmq
ptunnel					rabbitmq-c
puf					radamsa
pulledpork				radare2
pulseaudio				ragel
pup					rainbarf
pure-ftpd				rakudo-star
putmail					rancid
putmail-queue				randomize-lines
putty					ranger
pv					raptor
pwgen					rarian
pwnat					rasqal
pwsafe					rats
pxz					rbenv
py2cairo				rbenv-aliases
py3cairo				rbenv-binstubs
pyenv					rbenv-bundler
pyenv-ccache				rbenv-communal-gems
pyenv-virtualenv			rbenv-ctags
pyenv-virtualenvwrapper			rbenv-default-gems
pyenv-which-ext				rbenv-gemset
pyexiv2					rbenv-readline
pygobject				rbenv-use
pygobject3				rbenv-vars
pygtk					rbenv-whatis
pygtkglext				rc
pygtksourceview				rcs
pylucene				rcssserver
pypy					rdate
pypy3					rdfind
pyqt					rdiff-backup
pyqt5					rds-command-line-tools
pyqwt					rdup
pyside					re2
pyside-tools				re2c
python					readline
python3					readosm
q					reattach-to-user-namespace
qbs					reaver
qca					rebar
qcachegrind				reclass
qd					recode
qdbm					recoverjpeg
qemu					recutils
qjson					redis
qpdf					redland
qprint					redo
qrencode				redsocks
qscintilla2				redstore
qstat					regex-opt
qt					regina-rexx
qt5					regldg
qtfaststart				remake
remctl					s3sync
remind					safe-rm
ren					saltstack
rename					sam2p
renameutils				samba
reop					sane-backends
repl					sary
repo					sassc
reposurgeon				savana
rest-shell				saxon
resty					saxon-b
rethinkdb				sbcl
rexster-console				sbt
rfcdiff					sbuild
rfcmarkup				sc68
rfcstrip				scala
rgbds					scalastyle
rhash					scale2x
rhino					scamper
riak					scheme48
riemann					schroedinger
rig					scm-manager
rinetd					scons
ringojs					screenbrightness
ripmime					screenfetch
rkflashtool				screenresolution
rkhunter				scrollkeeper
rlog					scrub
rlwrap					scrypt
rmate					scsh
rmcast					sdcc
rmtrash					sdcv
rnv					sdf
robodoc					sdhash
rock					sdl
rocksdb					sdl2
rolldice				sdl2_gfx
roundup					sdl2_image
rp					sdl2_mixer
rpg					sdl2_net
rpl					sdl2_ttf
rpm					sdl_gfx
rpm2cpio				sdl_image
rrdtool					sdl_mixer
rsense					sdl_net
rsnapshot				sdl_rtf
rssh					sdl_sound
rsstail					sdl_ttf
rsyslog					sec
rt-audio				seexpr
rtf2latex2e				selecta
rtmpdump				selenium-server-standalone
rtorrent				sendemail
rtpbreak				ser2net
rubber					serd
ruby					serialosc
ruby-build				sersniff
ruby-install				setweblocthumb
runcocoa				sf-pwgen
runit					sfcgal
rush					sflowtool
rust					sfml
ry					sgrep
rzip					shadowsocks-libev
s-lang					shakespeare
s3cmd					shapelib
shared-mime-info			source-highlight
shellcheck				sox
shellinabox				spark
shiboken				sparkey
shivavg					spatialindex
shmcat					spatialite-gui
shmux					spatialite-tools
shntool					spawn-fcgi
shocco					spdylay
shorten					speedtest_cli
shrewsoft-vpn-client			speex
shtool					sphinx
shunit2					spidermonkey
sic					spim
sickbeard				spin
siege					spiped
signify-osx				splint
signing-party				spring-loaded
silc-client				spring-roo
silk					sproxy
simgrid					sqlcipher
simh					sqlite
simple-tiles				sqlitebrowser
since					sqliteman
sip					sqlmap
sipcalc					sqoop
sipp					sqsh
sipsak					squashfs
sisc-scheme				squid
sispmctl				squirrel
skipfish				sratom
skktools				srecord
skytools				srmio
sl					srtp
sleepwatcher				ssdb
sleuthkit				ssdeep
slimerjs				ssed
sloccount				ssh-copy-id
slony					sshguard
slowhttptest				sshrc
slrn					sshtrix
slurm					sshuttle
smake					ssldump
smartmontools				sslh
smartypants				sslscan
smlnj					ssreflect
snap7					ssss
snappy					st
snapraid				stanford-parser
snobol4					star
snort					stgit
snownews				stk
sntop					stklos
snzip					stlviewer
socat					stone
soccerwindow2				storm
soci					stow
sofia-sip				streamripper
solid					stress
solr					strongswan
somagic					stunnel
somagic-tools				stuntman
sonar					style-check
sonar-runner				sub2srt
sord					subliminal
sound-touch				submarine
subnetcalc				terraform
subversion				tesseract
suomi-malaga-voikko			testdisk
surfraw					tevent
suricata				texapp
svdlibc					texi2html
svg2pdf					texinfo
svg2png					thc-pptp-bruter
svtplay-dl				the_platinum_searcher
swaks					the_silver_searcher
swatchbooker				theharvester
swfmill					theora
swftools				thrift
swig					thrulay
swish-e					tidyp
switchaudio-osx				tiff2png
sword					tig
syck					tika
sync_gateway				timedog
syncthing				timelimit
synfig					timidity
synfigstudio				tin
sysbench				tinc
sysdig					tintin
szip					tiny-fugue
szl					tinycdb
t1lib					tinyproxy
t1utils					tinyscheme
ta-lib					tinysvm
tag					tinyxml
taglib					tinyxml2
taktuk					titan-server
tal					tivodecode
talk-filters				tkdiff
talloc					tlassemble
tarsnap					tlsdate
task					tmpreaper
task-spooler				tmpwatch
taskd					tmux
tbb					tmux-cssh
tcc					tmux-mem-cpu-load
tclap					tn5250
tcpflow					tnef
tcping					tnote
tcpreplay				todo-txt
tcpsplit				tofrodos
tcptrace				toilet
tcptraceroute				tokyo-cabinet
tcptrack				tokyo-dystopia
tcptunnel				tokyo-tyrant
tcpurify				tomcat
tcsh					tomcat-native
teapot					tomee-jax-rs
tee-clc					tomee-plume
teem					tomee-plus
teensy_loader_cli			tomee-webprofile
tegh					topgit
telepathy-gabble			tor
telepathy-glib				torrentcheck
telepathy-idle				torsocks
telepathy-mission-control		tpl
tenyr					tpp
term					tracebox
terminal-notifier			tractorgen
termrec					trafficserver
termshare				trafshow
trang					v
transcrypt				v8
translate-toolkit			vala
transmission				valabind
trash					valgrind
tre					valkyrie
tree					varnish
treecc					vassh
treeline				vault-cli
truecrack				vbindiff
tsung					vcdimager
tta					vcodex
ttf2eot					vcprompt
ttf2pt1					vcsh
ttfautohint				vde
tth					vera++
tty-clock				verilator
ttylog					vert.x
ttyrec					vf
ttytter					vgmstream
tuntap					vice
tutum					vifm
twemcache				vilistextum
two-lame				vim
txt2man					vimpager
txt2tags				vimpc
typesafe-activator			vip
typespeed				virtualhost.sh
u-boot-tools				virtualpg
uade					virtuoso
uberftp					visionmedia-watch
uchardet				visitors
ucl					visualnetkit
ucspi-tcp				vit
udis86					vmalloc
udns					vncsnapshot
udptunnel				vnstat
udpxy					volatility
udunits					voldemort
ufraw					voltdb
unac					voms
unar					vorbis-tools
unbound					vorbisgain
uncrustify				vowpal-wabbit
unfs3					vpnc
unifdef					vramsteg
unison					vrpn
unittest				vsftpd
unittest-cpp				vstr
unixodbc				vtclock
unoconv					vte
unp					vte3
unpaper					vttest
unrar					w-calc
unrtf					w3m
unshield				wait_on
uptimed					wakeonlan
upx					waon
uriparser				watch
urlview					watchman
uru					wavpack
usbmuxd					wbox
userspace-rcu				wdiff
utimer					web100clt
uudeview				webalizer
uwsgi					webfs
webkit2png				xqilla
webp					xrootd
weechat					xsane
weighttp				xspin
wemux					xstow
wget					xsw
wgetpaste				xtail
whatmask				xtitle
when					xulrunner
whirr					xvid
whitedb					xz
whohas					yacas
wiggle					yaf
wildfly-as				yafc
wimlib					yajl
wine					yamcha
winetricks				yamdi
winexe					yaml-cpp
wireshark				yap
wla-dx					yara
wordnet					yasm
wordplay				yaws
wput					yaz
wrangler				yaze-ag
writerperfect				yazpp
wrk					yconalyzer
wrk-trello				yeti
wry					ykclient
wtf					ykpers
wv					yle-dl
wv2					youtube-dl
wwwoffle				yubico-piv-tool
wxmac					yuicompressor
wxpython				yydecode
wy60					z
wyrd					z80asm
x11vnc					z80dasm
x264					zabbix
x265					zbackup
xa					zbar
xapian					zdelta
xaric					zebra
xbee-comm				zeromq
xcproj					zile
xctool					zinc
xdelta					zint
xerces-c				zmap
xlslib					znc
xml-coreutils				zookeeper
xml-security-c				zopfli
xml-tooling-c				zpaq
xml2					zpython
xmlcatmgr				zsh
xmlformat				zsh-completions
xmlrpc-c				zsh-history-substring-search
xmlsh					zsh-lovers
xmlstarlet				zsh-syntax-highlighting
xmlto					zshdb
xmltoman				zssh
xmp					zsync
xorriso					zxcc
xplanet					zzuf
xplanetfx
==> Deleted Formulae
adobe-air-sdk				gle
afuse					gnumeric
alpine-chappa				go-app-engine-32
app-engine-java-sdk			go-app-engine-64
archivemount				gobby
atari++					google-app-engine
auctex					google-perftools
authexec				googlecl
avfs					gpredict
bbcp					gptfdisk
bcwipe					grace
bindfs					graylog2-server
bochs					gsmartcontrol
cardpeek				gtk-chtheme
cdf					gtkglarea
cdimgtools				gtksourceviewmm
celt					gtksourceviewmm3
chktex					gtkwave
clay					guilt
clusterit				gv
coremod					hamsterdb
cppdom					hatari
cracklib-words				hexchat
curlftpfs				homebrew/versions/allegro5
cwm					homebrew/versions/elasticsearch-0.20
cyassl					homebrew/versions/elasticsearch090
datamash				homebrew/versions/elasticsearch11
dbslayer				homebrew/versions/llvm31
ddd					homebrew/versions/llvm32
dgtal					homebrew/versions/mapnik071
djmount					homebrew/versions/plowshare3
dmenu					honeyd
dupx					ifuse
dwm					imake
dzen2					inkscape
easy-tag				ipe
echoping				iptux
encfs					itsol
etcdctl					kbtin
ext2fuse				kernagic
ext4fuse				klavaro
feh					kumofs
fig					latex-mk
figtoipe				libcppa
finch					libqxt
fox					lilypond
freeglut				luarocks
freerdp					magit
fsharp					meld
fsv					mesalib-glw
fuse-zip				mess
fuse4x					mit-scheme
fuse4x-kext				morse
gant					mp3fs
geany					mpich2
geda-gaf				mscgen
geeqie					mupdf
geomview				mysql-connector-odbc
gerbv					mysql-proxy
ggobi					mysqlreport
giblib					net6
git-encrypt				newick-utils
git-flow-clone				nimrod
git-latexdiff				ntfs-3g
gkrellm					objective-caml
glade					offline-imap
ori					stormfs
paq8px					swi-prolog
par2tbb					sxiv
pari					sylpheed
pathfinder				tabbed
pcb					terminator
pdf-tools				texwrapper
pdf2image				ticcutils
pdfjam					tiger-vnc
pdftoipe				timbl
pebble-sdk				transmission-remote-gtk
perlmagick				tup
pgplot					uim
pixie					ume
plt-racket				upnp-router-control
polarssl				viewglob
pplatex					vobcopy
prooftree				wdfs
pure					wmctrl
pyenv-pip-rehash			wopr
pyxplot					wps2odt
qi					x3270
qiv					xar
rbenv-gem-rehash			xastir
rdesktop				xchat
rxvt-unicode				xclip
s3-backer				xdotool
s3fs					xdu
salt					xmount
scantailor				xournal
sdelta3					xpa
sedna					xpdf
shell.fm				xplot
sitecopy				xspringies
smartsim				yarp
sptk					ydict
sshfs					zenity
$ if [ "$TRAVIS_OS_NAME" == "osx" ]; then brew install sdl; fi
==> Downloading https://homebrew.bintray.com/bottles/sdl-1.2.15.mavericks.bottle
==> Pouring sdl-1.2.15.mavericks.bottle.2.tar.gz
🍺  /usr/local/Cellar/sdl/1.2.15: 223 files, 1.5M
$ if [ "$TRAVIS_OS_NAME" == "osx" ]; then brew install sdl2; fi
==> Downloading https://homebrew.bintray.com/bottles/sdl2-2.0.4.mavericks.bottle
==> Pouring sdl2-2.0.4.mavericks.bottle.tar.gz
🍺  /usr/local/Cellar/sdl2/2.0.4: 82 files, 4M
$ if [ "$TRAVIS_OS_NAME" == "osx" ]; then brew install glew; fi
==> Downloading https://homebrew.bintray.com/bottles/glew-1.13.0.mavericks.bottl
==> Pouring glew-1.13.0.mavericks.bottle.tar.gz
🍺  /usr/local/Cellar/glew/1.13.0: 34 files, 3.6M
$ if [ "$TRAVIS_OS_NAME" == "osx" ]; then brew install glm; fi
==> Downloading https://homebrew.bintray.com/bottles/glm-0.9.7.1.mavericks.bottl
==> Pouring glm-0.9.7.1.mavericks.bottle.tar.gz
🍺  /usr/local/Cellar/glm/0.9.7.1: 680 files, 12M
$ if [ "$TRAVIS_OS_NAME" == "osx" ]; then brew install homebrew/x11/mesalib-glw; fi
==> Tapping homebrew/x11
Cloning into '/usr/local/Library/Taps/homebrew/homebrew-x11'...
remote: Counting objects: 97, done.
remote: Compressing objects: 100% (97/97), done.
remote: Total 97 (delta 0), reused 11 (delta 0), pack-reused 0
Unpacking objects: 100% (97/97), done.
Checking connectivity... done.
Tapped 93 formulae (213 files, 253.2K)
==> Installing mesalib-glw from homebrew/x11
==> Downloading https://homebrew.bintray.com/bottles-x11/mesalib-glw-7.2.maveric
==> Pouring mesalib-glw-7.2.mavericks.bottle.1.tar.gz
🍺  /usr/local/Cellar/mesalib-glw/7.2: 6 files, 34K
$ autoreconf -i
aclocal: installing 'm4/libtool.m4' from '/usr/local/share/aclocal/libtool.m4'
aclocal: installing 'm4/ltoptions.m4' from '/usr/local/share/aclocal/ltoptions.m4'
aclocal: installing 'm4/ltsugar.m4' from '/usr/local/share/aclocal/ltsugar.m4'
aclocal: installing 'm4/ltversion.m4' from '/usr/local/share/aclocal/ltversion.m4'
aclocal: installing 'm4/lt~obsolete.m4' from '/usr/local/share/aclocal/lt~obsolete.m4'
aclocal: installing 'm4/pkg.m4' from '/usr/local/share/aclocal/pkg.m4'
glibtoolize: putting auxiliary files in `.'.
glibtoolize: copying file `./ltmain.sh'
configure.ac:7: installing './compile'
configure.ac:7: installing './config.guess'
configure.ac:7: installing './config.sub'
configure.ac:3: installing './install-sh'
configure.ac:3: installing './missing'
src/Makefile.am: installing './depcomp'

The command "autoreconf -i" exited with 0.
$ ./configure
checking for a BSD-compatible install... /usr/bin/install -c
checking whether build environment is sane... yes
checking for a thread-safe mkdir -p... ./install-sh -c -d
checking for gawk... no
checking for mawk... no
checking for nawk... no
checking for awk... awk
checking whether make sets $(MAKE)... yes
checking whether make supports nested variables... yes
checking build system type... x86_64-apple-darwin13.4.0
checking host system type... x86_64-apple-darwin13.4.0
checking how to print strings... printf
checking for style of include used by make... GNU
checking for gcc... gcc
checking whether the C compiler works... yes
checking for C compiler default output file name... a.out
checking for suffix of executables... 
checking whether we are cross compiling... no
checking for suffix of object files... o
checking whether we are using the GNU C compiler... yes
checking whether gcc accepts -g... yes
checking for gcc option to accept ISO C89... none needed
checking whether gcc understands -c and -o together... yes
checking dependency style of gcc... gcc3
checking for a sed that does not truncate output... /usr/bin/sed
checking for grep that handles long lines and -e... /usr/bin/grep
checking for egrep... /usr/bin/grep -E
checking for fgrep... /usr/bin/grep -F
checking for ld used by gcc... /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld
checking if the linker (/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld) is GNU ld... no
checking for BSD- or MS-compatible name lister (nm)... /usr/bin/nm
checking the name lister (/usr/bin/nm) interface... BSD nm
checking whether ln -s works... yes
checking the maximum length of command line arguments... 196608
checking whether the shell understands some XSI constructs... yes
checking whether the shell understands "+="... yes
checking how to convert x86_64-apple-darwin13.4.0 file names to x86_64-apple-darwin13.4.0 format... func_convert_file_noop
checking how to convert x86_64-apple-darwin13.4.0 file names to toolchain format... func_convert_file_noop
checking for /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld option to reload object files... -r
checking for objdump... no
checking how to recognize dependent libraries... pass_all
checking for dlltool... no
checking how to associate runtime and link libraries... printf %s\n
checking for ar... ar
checking for archiver @FILE support... no
checking for strip... strip
checking for ranlib... ranlib
checking command to parse /usr/bin/nm output from gcc object... ok
checking for sysroot... no
checking for mt... no
checking if : is a manifest tool... no
checking for dsymutil... dsymutil
checking for nmedit... nmedit
checking for lipo... lipo
checking for otool... otool
checking for otool64... no
checking for -single_module linker flag... yes
checking for -exported_symbols_list linker flag... yes
checking for -force_load linker flag... yes
checking how to run the C preprocessor... gcc -E
checking for ANSI C header files... yes
checking for sys/types.h... yes
checking for sys/stat.h... yes
checking for stdlib.h... yes
checking for string.h... yes
checking for memory.h... yes
checking for strings.h... yes
checking for inttypes.h... yes
checking for stdint.h... yes
checking for unistd.h... yes
checking for dlfcn.h... yes
checking for objdir... .libs
checking if gcc supports -fno-rtti -fno-exceptions... yes
checking for gcc option to produce PIC... -fno-common -DPIC
checking if gcc PIC flag -fno-common -DPIC works... yes
checking if gcc static flag -static works... no
checking if gcc supports -c -o file.o... yes
checking if gcc supports -c -o file.o... (cached) yes
checking whether the gcc linker (/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld) supports shared libraries... yes
checking dynamic linker characteristics... darwin13.4.0 dyld
checking how to hardcode library paths into programs... immediate
checking whether stripping libraries is possible... yes
checking if libtool supports shared libraries... yes
checking whether to build shared libraries... yes
checking whether to build static libraries... yes
checking whether we are using the GNU C++ compiler... yes
checking whether g++ accepts -g... yes
checking dependency style of g++... gcc3
checking how to run the C++ preprocessor... g++ -E
checking for ld used by g++... /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld
checking if the linker (/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld) is GNU ld... no
checking whether the g++ linker (/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld) supports shared libraries... yes
checking for g++ option to produce PIC... -fno-common -DPIC
checking if g++ PIC flag -fno-common -DPIC works... yes
checking if g++ static flag -static works... no
checking if g++ supports -c -o file.o... yes
checking if g++ supports -c -o file.o... (cached) yes
checking whether the g++ linker (/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/ld) supports shared libraries... yes
checking dynamic linker characteristics... darwin13.4.0 dyld
checking how to hardcode library paths into programs... immediate
checking for Boost headers version >= 0.0.0... yes
checking for Boost's header version... 1_55
checking for the toolset name used by Boost for g++... xgcc42 -xgcc
checking boost/program_options.hpp usability... yes
checking boost/program_options.hpp presence... yes
checking for boost/program_options.hpp... yes
checking for the Boost program_options library... yes
checking glm/glm.hpp usability... yes
checking glm/glm.hpp presence... yes
checking for glm/glm.hpp... yes
checking for pkg-config... /usr/local/bin/pkg-config
checking pkg-config is at least version 0.9.0... yes
checking for gl... no
configure: error: Package requirements (gl) were not met:

No package 'gl' found

Consider adjusting the PKG_CONFIG_PATH environment variable if you
installed software in a non-standard prefix.

Alternatively, you may set the environment variables gl_CFLAGS
and gl_LIBS to avoid the need to call pkg-config.
See the pkg-config man page for more details.

The command "./configure" exited with 1.
$ make
make: *** No targets specified and no makefile found.  Stop.

The command "make" exited with 2.

Done. Your build exited with 1.

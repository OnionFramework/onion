# Onion
## Onion
### Onion

C++ framework for meta-heuristic application development

<div align="center">

# zoxide

[![crates.io][crates.io-badge]][crates.io]
[![Downloads][downloads-badge]][releases]
[![Built with Nix][builtwithnix-badge]][builtwithnix]

zoxide is a **smarter cd command**, inspired by z and autojump.

It remembers which directories you use most frequently, so you can "jump" to
them in just a few keystrokes.<br />
zoxide works on all major shells.

[Getting started](#getting-started) •
[Installation](#installation) •
[Configuration](#configuration) •
[Integrations](#third-party-integrations)

</div>


<p align="center">
<a target="_blank" href="https://search.maven.org/artifact/com.webencyclop.core/mftool-java"><img src="https://img.shields.io/maven-central/v/com.webencyclop.core/mftool-java.svg?label=Maven%20Central"/></a> 
<a target="_blank" href="https://www.codacy.com/gh/ankitwasankar/mftool-java/dashboard?utm_source=github.com&utm_medium=referral&utm_content=ankitwasankar/mftool-java&utm_campaign=Badge_Coverage"><img src="https://app.codacy.com/project/badge/Coverage/0054db87ea0f426599c3a30b39291388" /></a>
<a href="https://www.codacy.com/gh/ankitwasankar/mftool-java/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ankitwasankar/mftool-java&amp;utm_campaign=Badge_Grade"><img src="https://app.codacy.com/project/badge/Grade/0054db87ea0f426599c3a30b39291388"/></a>
<a target="_blank" href="https://github.com/ankitwasankar/mftool-java/blob/master/license.md"><img src="https://camo.githubusercontent.com/8298ac0a88a52618cd97ba4cba6f34f63dd224a22031f283b0fec41a892c82cf/68747470733a2f2f696d672e736869656c64732e696f2f707970692f6c2f73656c656e69756d2d776972652e737667" /></a>
&nbsp <a target="_blank" href="https://www.linkedin.com/in/ankitwasankar/"><img height="20" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white" /></a>
</p>


[algorithm-aging]: https://github.com/ajeetdsouza/zoxide/wiki/Algorithm#aging
[algorithm-matching]: https://github.com/ajeetdsouza/zoxide/wiki/Algorithm#matching
[alpine linux packages]: https://pkgs.alpinelinux.org/packages?name=zoxide
[arch linux community]: https://archlinux.org/packages/community/x86_64/zoxide/
[asdf]: https://github.com/asdf-vm/asdf
[builtwithnix-badge]: https://img.shields.io/badge/builtwith-nix-7d81f7?logo=nixos&logoColor=white&style=flat-square
[builtwithnix]: https://builtwithnix.org/
[chocolatey]: https://community.chocolatey.org/packages/zoxide
[clink-zoxide]: https://github.com/shunsambongi/clink-zoxide
[clink]: https://github.com/mridgers/clink
[conda-forge]: https://anaconda.org/conda-forge/zoxide
[copr]: https://copr.fedorainfracloud.org/coprs/atim/zoxide/
[crates.io-badge]: https://img.shields.io/crates/v/zoxide?logo=rust&logoColor=white&style=flat-square
[crates.io]: https://crates.io/crates/zoxide
[debian packages]: https://packages.debian.org/stable/admin/zoxide
[devuan packages]: https://pkginfo.devuan.org/cgi-bin/package-query.html?c=package&q=zoxide
[downloads-badge]: https://img.shields.io/github/downloads/ajeetdsouza/zoxide/total?logo=github&logoColor=white&style=flat-square
[dports]: https://github.com/DragonFlyBSD/DPorts/tree/master/sysutils/zoxide
[emacs]: https://www.gnu.org/software/emacs/
[fedora packages]: https://src.fedoraproject.org/rpms/rust-zoxide
[felix]: https://github.com/kyoheiu/felix
[freshports]: https://www.freshports.org/sysutils/zoxide/
[fzf-installation]: https://github.com/junegunn/fzf#installation
[fzf-man]: https://manpages.ubuntu.com/manpages/en/man1/fzf.1.html
[fzf]: https://github.com/junegunn/fzf
[glob]: https://man7.org/linux/man-pages/man7/glob.7.html
[guru overlay]: https://github.com/gentoo-mirror/guru
[homebrew]: https://formulae.brew.sh/formula/zoxide
[issues]: https://github.com/ajeetdsouza/zoxide/issues/new
[joshuto]: https://github.com/kamiyaa/joshuto
[lf]: https://github.com/gokcehan/lf
[lf-wiki]: https://github.com/gokcehan/lf/wiki/Integrations#zoxide
[linuxbrew]: https://formulae.brew.sh/formula-linux/zoxide
[macports]: https://ports.macports.org/port/zoxide/summary
[neovim]: https://github.com/neovim/neovim
[nixpkgs]: https://github.com/NixOS/nixpkgs/blob/master/pkgs/tools/misc/zoxide/default.nix
[nnn-autojump]: https://github.com/jarun/nnn/blob/master/plugins/autojump
[nnn]: https://github.com/jarun/nnn
[opensuse factory]: https://build.opensuse.org/package/show/openSUSE:Factory/zoxide
[pkgsrc]: https://pkgsrc.se/sysutils/zoxide
[ranger-zoxide]: https://github.com/jchook/ranger-zoxide
[ranger]: https://github.com/ranger/ranger
[raspbian packages]: https://archive.raspbian.org/raspbian/pool/main/r/rust-zoxide/
[releases]: https://github.com/ajeetdsouza/zoxide/releases
[scoop]: https://github.com/ScoopInstaller/Main/tree/master/bucket/zoxide.json
[slackbuilds-howto]: https://slackbuilds.org/howto/
[telescope-zoxide]: https://github.com/jvgrootveld/telescope-zoxide
[telescope.nvim]: https://github.com/nvim-telescope/telescope.nvim
[termux]: https://github.com/termux/termux-packages/tree/master/packages/zoxide
[tmux-session-wizard]: https://github.com/27medkamal/tmux-session-wizard
[tutorial]: contrib/tutorial.webp
[ubuntu packages]: https://packages.ubuntu.com/jammy/zoxide
[vim]: https://github.com/vim/vim
[void linux packages]: https://github.com/void-linux/void-packages/tree/master/srcpkgs/zoxide
[wiki-env]: https://github.com/ajeetdsouza/zoxide/wiki/HOWTO:-set-environment-variables "HOWTO: set environment variables"
[xplr]: https://github.com/sayanarijit/xplr
[xxh-plugin-prerun-zoxide]: https://github.com/xxh/xxh-plugin-prerun-zoxide
[xxh]: https://github.com/xxh/xxh
[zabb]: https://github.com/Mellbourn/zabb
[zoxide.el]: https://gitlab.com/Vonfry/zoxide.el
[zoxide.vim]: https://github.com/nanotee/zoxide.vim
[zoxide.xplr]: https://github.com/sayanarijit/zoxide.xplr
[zsh-autocomplete]: https://github.com/marlonrichert/zsh-autocomplete

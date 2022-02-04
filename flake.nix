{
  inputs = {
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }: 
  flake-utils.lib.eachDefaultSystem (system:
    let
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      defaultPackage = pkgs.mkShell { 
        packages = with pkgs; [
          gnumake
          qmk 
          (writeShellScriptBin "setupSrc" ''
            #! /usr/bin/env bash
            ROOTDIR=$(git rev-parse --show-toplevel)
            QMK_SRC="$ROOTDIR/qmk_firmware"
            CRKBD="$QMK_SRC/keyboards/crkbd/"
            if [[ ! -d "$QMK_SRC" ]] 
            then
              echo "adding QMK src as a git submodule"
              git submodule add -f https://github.com/qmk/qmk_firmware
              git submodule update --init --recursive --progress
            fi

            if [[ ! -d "$CRKBD/keymaps/customkm" ]] 
            then
              echo "Creating keyboard src symbolic link"
              mkdir "$CRKBD/keymaps/customkm"
              ln -r -s crkbd/* $CRKBD/keymaps/customkm/
            fi

          '')
          (writeShellScriptBin "compileKeyboard" ''
            #! /usr/bin/env bash
            cd qmk_firmware
            qmk compile -kb crkbd -km customkm
          '')
          (writeShellScriptBin "flashKeyboard" ''
            #! /usr/bin/env bash
            cd qmk_firmware
            qmk flash -kb crkbd -km customkm
          '')
        ]; 
      };
    });
}

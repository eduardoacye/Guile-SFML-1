(define-module (sfml color)
  #:export (color-make
	    color-get-r
	    color-set-r!
	    color-get-g
	    color-set-g!
	    color-get-b
	    color-set-b!
	    color-get-a
	    color-set-a!
	    color-add
	    color-sub
	    color-mod
	    black
	    white
	    red
	    green
	    blue
	    yellow
	    magenta
	    cyan
	    transparent))

(load-extension "libguile-sfml" "init_sfml")

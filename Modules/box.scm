(define-module (sfml box)
  #:export (box-make
	    box-get-left
	    box-get-top
	    box-get-width
	    box-get-height
	    box-set-left!
	    box-set-top!
	    box-set-width!
	    box-set-height!
	    box-contains?
	    box-intersects?))

(load-extension "libguile-sfml" "init_sfml")

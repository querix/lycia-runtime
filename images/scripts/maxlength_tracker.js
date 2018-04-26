/**
 *  Copyright 2017 Querix Ltd
 *  Released under the MIT license.
 *
 *	Wrapper for counting/displaying remaining char size / characters to be entered into a textField (countDown)
 *  Must be used with maxlength_tracker.css
 *  4GL code to load maxlength_tracker:
 *  CALL ui.interface.frontcall("html5","scriptImport",["qx://application/scripts/maxlength_tracker.js","nowait"],[])
 *  CALL ui.interface.frontcall("html5","styleImport",["qx://application/scripts/maxlength_tracker.css","nowait"],[])
 */
(function(querix){

var $ = querix.$;
var api = querix.plugins.api;

var get$ = function(el) {
    try{
        if (el) {
          return el.getWindow().$;
        } else {
          return api.getWindow(api.topWindow()).$;
        }
    } catch (e) {
        if (console) {
          console.error('(Cannot get jQuery object of the top window',e.stack);
        }
        return null;
    }
};

var checkUnset = function(value, defaultValue) {
  if (typeof value === 'object' &&
    (value === querix.reactive.unset || value === querix.reactive.undef)) {
    return defaultValue;
  }
  return value;
}

var setMaxtrackerStyles = function($$) {
	var style = $$('#maxlength-tracker-styles');
	if (style.length == 0) {
		$$('head').append('<style id="maxlength-tracker-styles">'+maxlengthTrackerStyles+'</style>');
	}
}

querix.plugins.wrappers.maxlength_tracker = {
    wrap: function(childId, e, param) {
        var $$ = get$(e), dom, $text, maxlength;
        $text = e.find('.qx-text:first');
        maxlength = parseInt($text.attr('maxlength'));

        var instance = {
            prop: function(path,v) {
            	if (path === 'MaxLength' && parseInt(v) > 0) {
				    dom = $$('<div class="tracker" />');
				    $text = e.find('.qx-text:first');
            		maxlength = v;
            		dom.text(v);
				    $text.on('keyup',function(ev){
				    	var val;
				    	if (this.tagName === 'INPUT' || this.tagName === 'TEXTAREA') {
				    		val = $text.val();
				    	} else {
				    		val = $text.text();
				    	}
				    	var charsLeft = $text.attr('maxlength') - val.length;
						dom.html(charsLeft);
				    });
    				e.addClass("qx-maxlength-tracker").append(dom);
            	}
                return true;
            },
            attach: function() {
            	return true;
            },
            remove: function() {
            }
        };

        if (!isNaN(maxlength)) {
          instance.prop('MaxLength',maxlength);
        }

        return instance;
    }
};
})(querix);

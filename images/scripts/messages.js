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

function messagejs_onMouseDown() {
  doHide();
  var $$ = get$();
  if ($$ == null) {
    return;
  }
  $$("body").off("mousedown", messagejs_onMouseDown);
  $$("body").off("blur", messagejs_onMouseDown);
}

var getPopup = function($$) {
    var widget;
    if (!widget) {
        widget = $$('#message-popup');
        if (!widget.length) {
            widget = $$('<div id="message-popup">')
            .addClass("ui-tooltip ui-widget ui-corner-all ui-widget-content")
                .hide();
        $$("<div>")
            .addClass("ui-tooltip-content")
            .appendTo(widget);
        }
        widget.appendTo("body");
    }
    return widget;
};

var posOptFor = function(fld, $$) {
    var el = fld;
    /**
     *  Workaround for problem(bug?) with jQuery.setOffset():
     *  it obtains
     *  a) actual position of element
     *  b) position of element set in CSS
     *  and calculates resulting position as
     *  ( options.top - actualPosition.top ) + cssTop;
     *  If element has display:none or detached from DOM tree,
     *  but has CSS properties top/left set, result is incorrect.
     */
    var widget = $$('#message-popup');
    widget.css({display:'block'});
    if (fld.substring && fld === 'globalpos') {
      return globalpos;
    }
    if (fld.substr) {
        var prefix = ".qx-on-" + querix.childId;
        if (fld[0] !== "." && fld[0] !== "#" && fld[0] !== " ")
          el = prefix + ".qx-identifier-" + fld;
        else
          el = prefix + fld;
    }
    return {
        my: "center bottom-10",
        at: "center top",
        of: $$(el),
        using: function(position, feedback) {
            $$(this).css(position);
            $$("<div>")
                .addClass("arrow")
                .addClass(feedback.vertical)
                .addClass(feedback.horizontal)
                .appendTo(this);
        }
    };
};

var globalpos = {
    my: "right-20 top+20",
    at: "right top",
    of: "#qx-container-body"
};

var doHide = null;
var baseDoHide = doHide = function() {
    if (curTimeout) {
        clearTimeout(curTimeout);
        curTimeout = null;
    }
    var $$ = get$();
    if ($$ == null) {
      return;
    }
    var widget = $$('#message-popup');
    if (widget) {
        widget.fadeOut("slow");
    }
};

var curTimeout = null;
var msgs = querix.plugins.frontCallModuleList.messages = {
    // shows a pop up with field related information
    // if timeout is specified will be displayed for the
    // amount in seconds, if it is 0
    // only manual hidding is available (via hide method)
    // it will hide all other open tooltips automatically
    showForId: function(fieldid, content, timeout) {
        var $$ = get$();
        $$("body").on("mousedown", messagejs_onMouseDown);
        $$("body").on("blur", messagejs_onMouseDown);
        getPopup($$).hide().html(content).fadeIn().position(posOptFor(fieldid,$$));
        if (timeout > 0)
            curTimeout = setTimeout(doHide,timeout*1000);
    },
    // same as showForField but will be not bound to any field
    // it just will be shown in right-top corner
    showGlobal: function(content,timeout) {
        var $$ = get$();
        $$("body").on("mousedown", messagejs_onMouseDown);
        $$("body").on("blur", messagejs_onMouseDown);
        getPopup($$).hide().html(content).fadeIn().position(posOptFor('globalpos',$$));
        if (timeout > 0)
            curTimeout = setTimeout(doHide,timeout*1000);
    },
    // hides all pop ups
    hide: doHide
};

var popup = querix.plugins.wrappers.popup = {
    wrap: function(childId, e, param) {
        var wrappedElement;
        var attached;
        var timeout = 0;
        var el = e;
        var location = {x:undefined,y:undefined};
        if (param) {
            if ($.isNumeric(param))
                timeout = param;
            else if (param.substr) {
                if (param[0] !== "." && param[0] !== "#" && param[0] !== " ")
                    param = ".qx-identifier-" + param;
                attached = ".qx-on-" + querix.childId + param;
            }
        } else {
            attached = '.qx-identifier-rootcontainer:first';
        }
        var txt = null;
        var visible = true;
        el.detach();
        var instance = {
            _show: function() {
                var $$ = get$(e);
                if ($$ == null) {return;}
                var w = getPopup($$);
                w.fadeIn();
                doHide = instance._hide;
                if (timeout > 0)
                    curTimeout = setTimeout(doHide,timeout*1000);
                var ael = $$(attached);
                if (!(location.x === undefined || location.y === undefined) && ael.length == 0) {
                    var rc = wrappedElement.closest('.qx-identifier-rootcontainer');
                    if (rc.length == 0) {
                        rc = $$('body');
                    }
                    var offset = rc.offset();
                    var pos = {
                        my: 'left top',
                        at: location.x + ' ' + location.y,
                        of: rc,
                        using: function() {
                            var css = {
                                left: (offset.left + parseInt(location.x)) + 'px',
                                top: (offset.top + parseInt(location.y)) + 'px'
                            };
                            $(this).css(css);
                        }
                    };
                    w.position(pos);
                }
                else if (ael.length)
                    w.position(posOptFor(ael,$$));
                else
                    w.position(globalpos);
                $$("body").on("mousedown", messagejs_onMouseDown);
                $$("body").on("blur", messagejs_onMouseDown);
            },
            _hide: function() {
                var $$ = get$(e);
                if ($$ == null) {return;}
                doHide = baseDoHide;
                // signals the text of the element is empty, so
                // server will send next update even if the text's
                // value is the same
                api.setData(el,"");
                getPopup($$).fadeOut();
            },
            propLinkedTo: function(x) {
                attached = checkUnset(x);
            },
            propWrappedElement: function(x) {
                wrappedElement = x;
            },
            propVisible: function(v) {
                visible = v;
                if (v)
                  instance._show();
                else
                  instance._hide();
                return false;
            },
            propText: function(v) {
                var $$ = get$(e);
                if ($$ == null) {return;}
                var w = getPopup($$);
                w.html(v);
                if (visible)
                    instance._show();
                return false;
            },
            propX: function(v) {
                location.x = v;
            },
            propY: function(v) {
                location.y = v;
            },
            prop: function(path,v) {
                var fun = instance["prop"+path];
                if (fun)
                    fun.call(this,v);
                return false;
            },
            attach: function() { return false; },
            remove: function(sel,to) {
            }
        };
        return instance;
    }
};

querix.plugins.wrappers.popuperror = {
    wrap: function(childId, el, param) {
        var inner = popup.wrap(childId,el,param),
            prevShow = inner._show,
            prevHide = inner._hide;
        inner._show = function() {
            var $$ = get$(el);
            if ($$ == null) {return;}
            getPopup($$).addClass("error");
            prevShow.call(this);
        };
        inner._hide = function() {
            var $$ = get$(el);
            if ($$ == null) {return;}
            getPopup($$).removeClass("error");
            prevHide.call(this);
        };
        return inner;
    }
};

querix.plugins.wrappers.displayatredir = {
    wrap: function(childId,el,param) {
        var x = null,y = null, wrapped, paramArr,
            locationX = null, locationY = null,
            buf = [{p:'WrappedElement',v:el}], bLocation = false,
            update = function() {
                var i, cur, inner, j;
                if (wrapped)
                    return true;
                if (x === null || y === null || locationX === null || locationY === 0) {
                    return false;
                }
                for (i = 0; i < paramArr.length; i++) {
                    cur = paramArr[i];
                    if (!bLocation) {
                        if (cur.rows && $.inArray(y,cur.rows) === -1)
                            continue;
                        if (cur.cols && $.inArray(x,cur.cols) === -1)
                            continue;
                    }
                    if (!wrapped) {
                        inner = querix.plugins.wrappers[cur.to.toLowerCase()];
                        if (!inner)
                            continue;
                        wrapped = inner.wrap(childId,el,cur.parameter);
                        if (!wrapped)
                            continue;
                        if (buf.length) {
                            for(j = 0; j < buf.length; j++) {
                                cur = buf[j];
                                wrapped.prop(cur.p,cur.v);
                            }
                            buf.length = 0;
                        }
                        return true;
                    }
                }
                return false;
            };
        try {
            paramArr = JSON.parse(param);
            if (!paramArr || !paramArr.length)
                return null;
        } catch(e) {
            console.error('no parse for:',param);
            return null;
        }
        return {
            prop: function(path,v) {
                var i, cur, inner;
                if (path === "Location$XCoord") {
                    locationX = querix.rjqui.toUnitsW(v);
                    buf.push({p:'X',v:locationX});
                    update();
                    return false;
                }
                if (path === "Location$YCoord") {
                    locationY = querix.rjqui.toUnitsH(v);
                    buf.push({p:'Y',v:locationY});
                    update();
                    return false;
                }
                /**
                 *    As per vlne explanation(2016-10-31)
                 *    1. Target contains row/col from 4gl statement 'DISPLAY 'message' AT <row>,<col>'
                 *    in format <window_id>.AT_<row>_<col>
                 *    2. Location, GridItemLocation are not needed
                 */

                if (path === "Target") {
                    var arr = /^.*\.AT_(\d+)_(\d+)/.exec(v);
                    y = parseInt(arr[1]);
                    x = parseInt(arr[2]);
                    bLocation = false;
                    buf.push({p:'AT',v:{X:x,Y:y}});
                    update();
                    return false;
                }

                if (update())
                    wrapped.prop(path,v,x,y);
                else
                    buf.push({p:path,v:v});
                return false;
            },
            attach: function(to) {
                return false;
            },
            remove: function(el,to) {
            }

        };
    }
};

querix.plugins.wrappers.console = {
    wrap: function(childId,el,param) {
        var pText = null, pAt = null, prevText;
        return {
            prop: function(n,v,x,y) {
                if (n === "Text" && v != prevText && x != null && y != null) {
                    querix.rjqui.textConsole.append('AT '+x+','+y+': '+v,function(){});
                    prevText = v;
                    pText = pAt = null;
                    return;
                } else {
                    if (n === "Text" && v != prevText) {
                        pText = v;
                    } else if (n === "AT") {
                        pAt = v;
                    }
                    if (pText && pAt) {
                        querix.rjqui.textConsole.append('AT '+pAt.X+','+pAt.Y+': '+pText,function(){});
                        prevText = pText;
                        pText = pAt = null;
                    }
                }
            },
            attach: function() { return false; }
        };

    }
};

/* attaches the element to some different DOM node */
querix.plugins.wrappers.attachto = {
    wrap: function(childId,el,sel) {
        var isAttached = false;
        var instance = {
            attach: function(to) {
                var $$ = get$(el);
                if ($$ == null) {return;}
                $$(sel).children().detach().end().html(el.qx$outer());
                isAttached = true;
                return false;
            },
            propContent: function(v) {
                if (!isAttached) {
                  this.attach();
                }
                var x = el.children().detach().end();
                x.html(v);
            },
            propText: function(v) {
                instance.propContent(v);
            },
            prop: function(path,v) {
                var fun = instance["prop"+path];
                if (fun) {
                    fun.call(this,v);
                    return false;
                }
                return true;
            }
        };
        return instance;
    }
};

/* moves text from an element to DOM element specified in Parameter */
querix.plugins.wrappers.textto = {
    wrap: function(childId,e,sel) {
        function setTextTo($collection,t) {
            $collection.each(function(i, el){
                var $$ = get$(e);
                if ($$ == null) {return;}
                var $el = $$(el);
                var tagName = $el[0].tagName;
                if (tagName === 'INPUT' || tagName === 'TEXTAREA') {
                    $el.val(t);
                } else {
                    $el.text(t);
                }
            });
        }
        var instance = {
            propText: function(v) {
                var $$ = get$(e);
                if ($$ == null) {return;}
                setTextTo($$(sel),v);
            },
            propVisible: function(v) {
                if (!v) {
                    var $$ = get$(e);
                    if ($$ == null) {return;}
                    setTextTo($$(sel),'');
                }
            },
            propCollapsed: function(v) {
                if (!v) {
                    var $$ = get$(e);
                    if ($$ == null) {return;}
                    setTextTo($$(sel),'');
                }
            },
            prop: function(path,v) {
                var fun = instance["prop"+path];
                if (fun)
                    fun.call(this,v);
                return false;
            }
        };
        return instance;
    }
};

})(querix);

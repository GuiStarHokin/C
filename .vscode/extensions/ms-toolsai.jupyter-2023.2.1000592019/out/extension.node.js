/*! For license information please see extension.node.js.LICENSE.txt */
                            try:
                                del _VSCODE_getVariable
                            except:
                                pass
                            `;let Xl=Hl=class{constructor(e,t){this.fs=e,this.context=t}async generateCodeToGetVariableInfo(e){const t=await this.getContentsOfScript(),n=e.isDebugging?"True":"False",r=`${Yl}("info", ${n}, ${e.variableName})`;return e.isDebugging?{initializeCode:t,code:r,cleanupCode:Ql}:{code:`${t}\n\n${r}\n\n${Ql}`}}async generateCodeToGetVariableProperties(e){const t=await this.getContentsOfScript(),n=e.isDebugging?"True":"False",r=`${Yl}("properties", ${n}, ${e.variableName}, ${e.stringifiedAttributeNameList})`;return e.isDebugging?{initializeCode:t,code:r,cleanupCode:Ql}:{code:`${t}\n\n${r}\n\n${Ql}`}}async generateCodeToGetVariableTypes(e){const t=`${await this.getContentsOfScript()}\n\n_VSCODE_rwho_ls = %who_ls\n`,n=e.isDebugging?"True":"False",r=zl()`
        try:
            del _VSCODE_rwho_ls
        except:
            pass
        `,i=`${Yl}("types", ${n}, _VSCODE_rwho_ls)`;return e.isDebugging?{initializeCode:t,code:i,cleanupCode:`${Ql}\n${r}`}:{code:`${t}${i}\n\n${Ql}\n${r}`}}async getContentsOfScript(){if(Hl.contentsOfScript)return Hl.contentsOfScript;const e=Ln(this.context.extensionUri,"pythonFiles","vscode_datascience_helpers","getVariableInfo","vscodeGetVariableInfo.py"),t=await this.fs.readFile(e);return Hl.contentsOfScript=t,t}};Xl=Hl=function(e,t,n,r){var i,o=arguments.length,s=o<3?t:null===r?r=Object.getOwnPropertyDescriptor(t,n):r;if("object"==typeof Reflect&&"function"==typeof Reflect.decorate)s=Reflect.decorate(e,t,n,r);else for(var a=e.length-1;a>=0;a--)(i=e[a])&&(s=(o<3?i(s):o>3?i(t,n,s):i(t,n))||s);return o>3&&s&&Object.defineProperty(t,n,s),s}([(0,Ut.b2)(),Gl(0,(0,Ut.f3)(Uo)),Gl(1,(0,Ut.f3)(en))],Xl);var Zl,ed=function(e,t){return function(n,r){t(n,r,e)}};const td="_VSCODE_getDataFrame",nd=zl()`
                            try:
                                del _VSCODE_getDataFrame
                            except:
                                pass
        try:
            import ipywidgets as _VSCODE_ipywidgets
            print("${Cg}" + _VSCODE_ipywidgets.__version__)
            del _VSCODE_ipywidgets
        except:
            pass
//# sourceMappingURL=extension.node.js.map